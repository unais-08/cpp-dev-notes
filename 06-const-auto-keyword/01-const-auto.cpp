/**
 * File: 01-cpp-const-auto.cpp
 * Description: A brief tutorial on the 'const' and 'auto' keywords in C++,
 * explaining their core functionalities and common use cases.
 */

#include <iostream>  // For std::cout, std::endl
#include <string>    // For std::string
#include <vector>    // For std::vector
#include <map>       // For std::map

// =========================================================================
// 1. Introduction: const and auto
// =========================================================================

/**
 * **1. Introduction: `const` and `auto`**
 * -   **`const`:** A type qualifier that signifies immutability. It tells the compiler
 * that a value, pointer, or reference should not be modified. Crucial for safety,
 * correctness, and optimization.
 * -   **`auto`:** A type specifier (C++11 onwards) that instructs the compiler to
 * automatically deduce the type of a variable from its initializer. It improves
 * readability and reduces verbosity, especially with complex types.
 */

// =========================================================================
// 2. The `const` Keyword: Immutability
// =========================================================================

/**
 * **2. The `const` Keyword: Immutability**
 * -   `const` means "read-only" or "cannot be modified."
 * -   It's a compile-time guarantee. The compiler enforces `const` correctness.
 */

/**
 * **2.1. `const` Variables:**
 * -   The value of a `const` variable cannot be changed after initialization.
 * -   Must be initialized at the point of declaration.
 */
void demonstrateConstVariables()
{
    const int MAX_VALUE = 100;  // MAX_VALUE is a constant
    // MAX_VALUE = 150; // ERROR: cannot assign to a variable that is const
    std::cout << "2.1 Max Value: " << MAX_VALUE << std::endl;
}

/**
 * **2.2. `const` with Pointers:**
 * -   This is a common source of confusion. The position of `const` matters.
 * -   **`const T* ptr;` (Pointer to `const` data):** The data pointed to cannot be modified through
 * this pointer. The pointer itself *can* be changed to point to another location.
 * -   **`T* const ptr;` (`const` pointer to non-`const` data):** The pointer itself cannot be
 * changed to point to another location. The data pointed to *can* be modified through this pointer.
 * -   **`const T* const ptr;` (`const` pointer to `const` data):** Neither the data pointed to nor
 * the pointer itself can be modified.
 */
void demonstrateConstPointers()
{
    int value = 10;
    int anotherValue = 20;

    // Pointer to const data
    const int* ptr_to_const_data = &value;
    // *ptr_to_const_data = 15; // ERROR: cannot modify data through this pointer
    ptr_to_const_data = &anotherValue;  // OK: pointer can be reseated
    std::cout << "2.2 Pointer to const data: " << *ptr_to_const_data << std::endl;

    // Const pointer to non-const data
    int* const const_ptr = &value;
    *const_ptr = 15;  // OK: data can be modified through this pointer
    // const_ptr = &anotherValue; // ERROR: pointer cannot be reseated
    std::cout << "2.2 Const pointer: " << *const_ptr << std::endl;

    // Const pointer to const data
    const int const_value = 30;
    const int* const const_ptr_to_const_data = &const_value;
    // *const_ptr_to_const_data = 35; // ERROR
    // const_ptr_to_const_data = &anotherValue; // ERROR
    std::cout << "2.2 Const pointer to const data: " << *const_ptr_to_const_data << std::endl;
}

/**
 * **2.3. `const` with References:**
 * -   **`const T& ref;` (`const` reference):** The data referenced cannot be modified through this
 * reference.
 * -   Similar to `const T*`, but references must be initialized and cannot be reseated.
 * -   Can bind to `const` variables, non-`const` variables, and even temporary values (rvalues).
 */
void printConstReference(const int& num)
{
    // num++; // ERROR: cannot modify through a const reference
    std::cout << "2.3 Value via const reference: " << num << std::endl;
}

/**
 * **2.4. `const` Member Functions:**
 * -   For class member functions, `const` placed after the parameter list (`void func() const;`)
 * indicates that the function will not modify the state (member variables) of the object it's
 * called on.
 * -   It can only call other `const` member functions.
 */
class MyClass
{
    int value;

   public:
    MyClass(int v) : value(v) {}
    int getValue() const
    {  // This function does not modify 'value'
        // value++; // ERROR: cannot modify member in const function
        return value;
    }
    void setValue(int v)
    {  // This function modifies 'value'
        value = v;
    }
};

// =========================================================================
// 3. The `auto` Keyword: Type Deduction
// =========================================================================

/**
 * **3. The `auto` Keyword: Type Deduction**
 * -   `auto` allows the compiler to automatically deduce the type of a variable from its
 * initializer.
 * -   Reduces verbosity, especially with complex types (e.g., iterators, lambda types).
 * -   **Requires an initializer:** `auto` variables must be initialized at declaration.
 */

/**
 * **3.1. Basic `auto` Usage:**
 * -   Replaces explicit type names.
 */
void demonstrateAutoBasic()
{
    auto integer = 10;                       // int
    auto floating = 3.14;                    // double
    auto character = 'A';                    // char
    auto text = "Hello";                     // const char* (C-style string literal)
    auto cpp_string = std::string("World");  // std::string

    std::cout << "3.1 Auto deduced types: " << std::endl;
    std::cout << "integer: " << integer << ", type: " << typeid(integer).name() << std::endl;
    std::cout << "floating: " << floating << ", type: " << typeid(floating).name() << std::endl;
    std::cout << "character: " << character << ", type: " << typeid(character).name() << std::endl;
    std::cout << "text: " << text << ", type: " << typeid(text).name() << std::endl;
    std::cout << "cpp_string: " << cpp_string << ", type: " << typeid(cpp_string).name()
              << std::endl;
}

/**
 * **3.2. `auto` with Complex Types (Iterators):**
 * -   Significantly improves readability when dealing with long type names.
 */
void demonstrateAutoIterators()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    // Without auto: std::vector<int>::iterator it = numbers.begin();
    auto it = numbers.begin();  // 'it' is deduced as std::vector<int>::iterator
    std::cout << "3.2 First element via auto iterator: " << *it << std::endl;

    std::map<std::string, int> ages = {{"Alice", 30}, {"Bob", 25}};
    // Without auto: for (std::map<std::string, int>::const_iterator pair_it = ages.begin(); ...
    for (auto const& pair_it : ages)
    {  // 'pair_it' is deduced as const std::pair<const std::string, int>&
        std::cout << "3.2 Map element: " << pair_it.first << " -> " << pair_it.second << std::endl;
    }
}

/**
 * **3.3. `auto` and References (`auto&`, `const auto&`):**
 * -   `auto` alone drops `const` and reference qualifiers. To preserve them, use `auto&` or `const
 * auto&`.
 * -   **`auto&`:** Deduce the type and make it a reference. Preserves `const` if the initializer is
 * `const`.
 * -   **`const auto&`:** Deduce the type and make it a `const` reference. Always results in a
 * `const` reference.
 */
void demonstrateAutoReferences()
{
    int x = 10;
    const int y = 20;

    auto a = x;  // 'a' is int (copy of x)
    auto b = y;  // 'b' is int (copy of y, const dropped)

    auto& ref_a = x;  // 'ref_a' is int& (reference to x)
    auto& ref_b = y;  // 'ref_b' is const int& (reference to y, const preserved)
    // ref_b = 25; // ERROR: cannot modify through const reference

    const auto& const_ref_x = x;  // 'const_ref_x' is const int&
    const auto& const_ref_y = y;  // 'const_ref_y' is const int&
    // const_ref_x = 15; // ERROR
    // const_ref_y = 25; // ERROR

    std::cout << "3.3 Auto references: " << std::endl;
    std::cout << "x: " << x << ", ref_a: " << ref_a << ", ref_b: " << ref_b << std::endl;
}

/**
 * **3.4. `auto` Limitations and Considerations:**
 * -   **No uninitialized `auto`:** `auto x;` is an error.
 * -   **No `auto` for function parameters (yet):** `void func(auto x) {}` is not allowed (except in
 * C++20 for lambdas).
 * -   **No `auto` for return types (direct):** `auto func() { return 10; }` is allowed (C++14
 * onwards).
 * -   **Array Decay:** `auto arr = {1, 2, 3};` deduces `std::initializer_list<int>`, not an array.
 * `auto arr[] = {1, 2, 3};` is not allowed.
 * -   **Readability:** While `auto` reduces verbosity, sometimes explicit types improve clarity for
 * complex logic. Use judiciously.
 */

// =========================================================================
// 4. Conclusion
// =========================================================================

/**
 * **4. Conclusion**
 * -   **`const`:** Essential for defining immutable data, enhancing code safety,
 * enabling compiler optimizations, and clearly communicating intent. Mastering its
 * application to variables, pointers, references, and member functions is fundamental.
 * -   **`auto`:** A powerful C++11 feature that simplifies code by allowing the compiler
 * to deduce types. It's particularly useful with complex template types and iterators,
 * improving readability and reducing typing errors. Use `auto&` or `const auto&` to
 * preserve reference and `const` qualifiers during deduction.
 * Both keywords contribute significantly to writing modern, efficient, and robust C++ code.
 */

// =========================================================================
// Main Function (Entry Point of the Program)
// =========================================================================

int main()
{
    std::cout << "--- 2. The const Keyword ---" << std::endl;
    demonstrateConstVariables();
    demonstrateConstPointers();
    int valForConstRef = 123;
    printConstReference(valForConstRef);
    printConstReference(456);  // Binds to a temporary rvalue

    MyClass obj(7);
    std::cout << "2.4 MyClass value (const func): " << obj.getValue() << std::endl;
    obj.setValue(8);
    std::cout << "2.4 MyClass value (after set): " << obj.getValue() << std::endl;

    std::cout << "\n--- 3. The auto Keyword ---" << std::endl;
    demonstrateAutoBasic();
    demonstrateAutoIterators();
    demonstrateAutoReferences();

    std::cout << "\n--- End of Tutorial ---" << std::endl;

    return 0;
}
