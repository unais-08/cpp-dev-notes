/**
 * File: 01-cpp-templates.cpp
 * Description: A professional and beginner-friendly tutorial on C++ Templates,
 * covering fundamental concepts like function templates, class templates,
 * non-type template parameters, basic template metaprogramming,
 *and best practices.
 * Date: 2025-06-26
 */

#include <iostream>     // For std::cout, std::endl
#include <string>       // For std::string
#include <vector>       // For std::vector in examples
#include <type_traits>  // For std::is_arithmetic_v (C++20 Concepts example)

// =========================================================================
// 1. Introduction: What are Templates? (The Generic Tool Analogy)
// =========================================================================

/**
 * **1. Introduction: What are Templates?**
 * -   In C++, **templates** are a powerful feature that allows you to write
 * generic programs.
 * -   Think of templates as a "fill-in-the-blank" mechanism for functions and classes.
 * Instead of writing separate code for `int`, `double`, `std::string`, etc.,
 * you write one generic piece of code that works with *any* data type.
 * -   This is known as **Generic Programming**.
 * -   **Why use templates?**
 * -   **Code Reusability:** Write code once, use it for many different types.
 * -   **Type Safety:** The compiler checks types at compile time, preventing
 * runtime errors that might occur with generic pointers (`void*`) or macros.
 * -   **Performance:** The compiler generates specialized code for each type
 * used, often resulting in performance comparable to hand-written code for specific types.
 * -   **DRY Principle (Don't Repeat Yourself):** Avoids writing identical logic
 * for different types.
 */

// =========================================================================
// 2. Function Templates
// =========================================================================

/**
 * **2. Function Templates**
 * -   A **function template** defines a family of functions.
 * -   The `template <typename T>` or `template <class T>` syntax declares a
 * type parameter `T` that can be any data type.
 * -   When you call a template function, the compiler deduces the type `T` from
 * the arguments you pass and generates a specific version of the function
 * (called a **template instantiation**) for that type.
 */

// Example 2.1: Basic Function Template (finding the maximum of two values)
template <typename T>  // Declares 'T' as a type parameter
T maximum(T a, T b)
{
    // This function will work for int, double, float, char, std::string, etc.
    // as long as the '>' operator is defined for type T.
    return (a > b) ? a : b;
}

// Example 2.2: Template Argument Deduction
// The compiler automatically figures out what 'T' should be based on the arguments.
void demonstrateFunctionTemplates()
{
    std::cout << "\n--- 2. Function Templates Example ---" << std::endl;

    // Using maximum with int
    int max_int = maximum(5, 10);                            // T is deduced as int
    std::cout << "2.1 Max (int): " << max_int << std::endl;  // Output: 10

    // Using maximum with double
    double max_double = maximum(3.14, 2.718);                      // T is deduced as double
    std::cout << "2.1 Max (double): " << max_double << std::endl;  // Output: 3.14

    // Using maximum with std::string (lexicographical comparison)
    std::string s1 = "apple";
    std::string s2 = "zebra";
    std::string max_string = maximum(s1, s2);                      // T is deduced as std::string
    std::cout << "2.1 Max (string): " << max_string << std::endl;  // Output: zebra

    // Note: Mixing types (e.g., maximum(5, 10.0)) would typically cause a compilation error
    // because T cannot be deduced as both int and double. You'd need explicit casting
    // or a more complex template.
}

/**
 * **2.3. Overloading Function Templates:**
 * -   Just like regular functions, function templates can be overloaded.
 * -   This means you can have multiple templates with the same name but different
 * parameter lists, or even a non-template function with the same name.
 * -   The compiler uses rules to decide which function (template or non-template)
 * is the best match.
 */

// Example 2.3.1: Overloading Function Template
template <typename T>
void print(T value)
{
    std::cout << "2.3.1 Generic print: " << value << std::endl;
}

template <typename T1, typename T2>
void print(T1 val1, T2 val2)
{
    std::cout << "2.3.1 Pair print: " << val1 << ", " << val2 << std::endl;
}

// Non-template overload for char* (might be preferred for C-style strings)
void print(const char* str)
{
    std::cout << "2.3.1 C-style string print: " << str << std::endl;
}

void demonstrateFunctionTemplateOverloading()
{
    std::cout << "\n--- 2.3.1 Function Template Overloading Example ---" << std::endl;
    print(123);           // Calls generic print<int>(int)
    print(3.14);          // Calls generic print<double>(double)
    print("Hello C++!");  // Calls non-template print(const char*)
    print(10, "World");   // Calls pair print<int, const char*>(int, const char*)
}

/**
 * **2.4. Explicit Template Arguments:**
 * -   Sometimes, the compiler cannot deduce the template arguments, or you want
 * to explicitly specify them.
 * -   You can do this using angle brackets `<>` after the function name.
 */

// Example 2.4.1: Explicit Template Arguments
template <typename R, typename A>  // R for return type, A for argument type
R convertAndAdd(A val1, A val2)
{
    return static_cast<R>(val1 + val2);
}

void demonstrateExplicitTemplateArguments()
{
    std::cout << "\n--- 2.4.1 Explicit Template Arguments Example ---" << std::endl;

    // Compiler cannot deduce R from arguments, must be specified:
    double result1 = convertAndAdd<double>(5, 10);                                // R=double, A=int
    std::cout << "2.4.1 convertAndAdd<double>(5, 10): " << result1 << std::endl;  // Output: 15.0

    int result2 = convertAndAdd<int>(5.5, 4.2);  // R=int, A=double (truncates)
    std::cout << "2.4.1 convertAndAdd<int>(5.5, 4.2): " << result2 << std::endl;  // Output: 9
}

// =========================================================================
// 3. Class Templates
// =========================================================================

/**
 * **3. Class Templates**
 * -   A **class template** defines a family of classes.
 * -   It allows a class to operate on generic types, providing type-safe data structures.
 * -   Examples in the Standard Library: `std::vector<T>`, `std::map<Key, Value>`,
 * `std::pair<T1,T2>`.
 */

// Example 3.1: Basic Class Template (a generic Pair)
template <typename T1, typename T2>  // Two type parameters
class Pair
{
   private:
    T1 first;
    T2 second;

   public:
    // Constructor for the Pair class template
    Pair(T1 f, T2 s) : first(f), second(s) { std::cout << "3.1 Pair object created." << std::endl; }

    // Member function to get the first element
    T1 getFirst() const { return first; }

    // Member function to get the second element
    T2 getSecond() const { return second; }

    // Member function to display the pair
    void display() const
    {
        std::cout << "3.1 Pair: (" << first << ", " << second << ")" << std::endl;
    }
};

/**
 * **3.2. Class Template Instantiation:**
 * -   To create an object from a class template, you must specify the actual types
 * for the template parameters in angle brackets `<>`.
 */
void demonstrateClassTemplates()
{
    std::cout << "\n--- 3. Class Templates Example ---" << std::endl;

    // Create a Pair of int and double
    Pair<int, double> p1(10, 20.5);
    p1.display();  // Output: Pair: (10, 20.5)

    // Create a Pair of std::string and char
    Pair<std::string, char> p2("Hello", 'W');
    p2.display();  // Output: Pair: (Hello, W)

    // Accessing members
    std::cout << "3.2 p1.getFirst(): " << p1.getFirst() << std::endl;
    std::cout << "3.2 p2.getSecond(): " << p2.getSecond() << std::endl;
}

/**
 * **3.3. Default Template Arguments:**
 * -   Similar to function parameters, class template parameters can have default values.
 * -   These defaults are used if the user doesn't explicitly specify a type for that parameter.
 */

// Example 3.3.1: Class Template with Default Arguments
template <typename T = int, int N = 10>  // T defaults to int, N defaults to 10
class FixedArray
{
   private:
    T arr[N];  // Array of type T with size N

   public:
    FixedArray()
    {
        std::cout << "3.3.1 FixedArray<" << typeid(T).name() << ", " << N << "> created."
                  << std::endl;
        for (int i = 0; i < N; ++i)
        {
            arr[i] = T();  // Initialize elements (requires T to be default-constructible)
        }
    }

    // Access operator
    T& operator[](int index)
    {
        if (index < 0 || index >= N)
        {
            // In real code, throw an exception or handle error properly
            std::cerr << "Error: Array index out of bounds!" << std::endl;
            // Return a reference to a dummy value or exit, for simplicity here
            // this is just to avoid compiler warning for not returning a value.
            static T dummy_val = T();
            return dummy_val;
        }
        return arr[index];
    }

    const T& operator[](int index) const
    {
        if (index < 0 || index >= N)
        {
            std::cerr << "Error: Array index out of bounds (const)!" << std::endl;
            static T dummy_val = T();
            return dummy_val;
        }
        return arr[index];
    }

    void fill(const T& value)
    {
        for (int i = 0; i < N; ++i)
        {
            arr[i] = value;
        }
    }

    void display() const
    {
        std::cout << "3.3.1 FixedArray elements: [";
        for (int i = 0; i < N; ++i)
        {
            std::cout << arr[i] << (i == N - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
};

void demonstrateDefaultTemplateArguments()
{
    std::cout << "\n--- 3.3.1 Default Template Arguments Example ---" << std::endl;

    FixedArray<> fa1;  // Uses default T=int, N=10
    fa1.fill(7);
    fa1.display();  // Output: FixedArray<int, 10> created. FixedArray elements: [7, 7, ...]

    FixedArray<double> fa2;  // Uses default N=10, T=double
    fa2.fill(3.14);
    fa2.display();  // Output: FixedArray<double, 10> created. FixedArray elements: [3.14, 3.14,
                    // ...]

    FixedArray<std::string, 3> fa3;  // T=std::string, N=3
    fa3.fill("abc");
    fa3.display();  // Output: FixedArray<std::string, 3> created. FixedArray elements: [abc, abc,
                    // abc]
}

// =========================================================================
// 4. Non-Type Template Parameters
// =========================================================================

/**
 * **4. Non-Type Template Parameters**
 * -   Besides type parameters (`typename T`), templates can also accept
 * non-type parameters.
 * -   These are constant values (like integers, enums, pointers, or references)
 * that are known at compile time.
 * -   Commonly used for sizes, dimensions, or flags.
 */

// Example 4.1: Non-Type Template Parameters (using FixedArray from above, N is non-type parameter)
// The FixedArray class template in 3.3.1 already demonstrates this.
// T is a type parameter, N is a non-type (integer) parameter.

void demonstrateNonTypeTemplateParameters()
{
    std::cout << "\n--- 4. Non-Type Template Parameters Example (See 3.3.1 for FixedArray) ---"
              << std::endl;
    // FixedArray<int, 5> is an instantiation where '5' is a non-type template parameter.
    FixedArray<int, 5> myIntArray;
    myIntArray.fill(42);
    myIntArray.display();  // Output: FixedArray<int, 5> created. FixedArray elements: [42, 42, 42,
                           // 42, 42]

    FixedArray<bool, 2> myBoolArray;
    myBoolArray.fill(true);
    myBoolArray.display();  // Output: FixedArray<bool, 2> created. FixedArray elements: [1, 1]
                            // (true often prints as 1)
}

// =========================================================================
// 5. Template Metaprogramming (TMP) - A Glimpse
// =========================================================================

/**
 * **5. Template Metaprogramming (TMP) - A Glimpse**
 * -   TMP is the use of C++ templates to perform computations at compile time.
 * -   It's a form of "programming with types" and "values known at compile time."
 * -   Commonly used for:
 * -   Type traits (querying properties of types).
 * -   Compile-time computations (e.g., factorials, Fibonacci).
 * -   Generating specialized code paths based on type characteristics.
 * -   Modern C++ features like `constexpr` and `if constexpr` often provide
 * simpler alternatives for compile-time logic compared to traditional TMP.
 */

// Example 5.1: Compile-time Factorial using recursion (classic TMP example)
template <int N>
struct Factorial
{
    // Recursively compute N * Factorial<(N-1)>
    static const long long value = N * Factorial<N - 1>::value;
};

// Base case for the recursion: Factorial<0>
template <>  // Explicit specialization for N=0
struct Factorial<0>
{
    static const long long value = 1;
};

void demonstrateTemplateMetaprogramming()
{
    std::cout << "\n--- 5. Template Metaprogramming Example ---" << std::endl;

    // The factorial is computed at compile time!
    long long fact5 = Factorial<5>::value;  // Value is 120, computed at compile time
    std::cout << "5.1 Factorial<5>::value = " << fact5 << std::endl;  // Output: 120

    long long fact7 = Factorial<7>::value;  // Value is 5040, computed at compile time
    std::cout << "5.1 Factorial<7>::value = " << fact7 << std::endl;  // Output: 5040
}

// =========================================================================
// 6. Concepts (C++20 and Beyond) - Improving Templates
// =========================================================================

/**
 * **6. Concepts (C++20 and Beyond)**
 * -   Concepts are a C++20 feature that allows you to specify constraints on template parameters.
 * -   They define semantic requirements on types (what operations a type must support).
 * -   **Benefits:**
 * -   **Improved Error Messages:** Compiler errors are much clearer when template arguments
 * don't satisfy a concept.
 * -   **Better Readability:** Code becomes self-documenting about type requirements.
 * -   **More Robust Generic Code:** Ensures that only valid types are used with a template.
 * -   Syntax: `template <ConceptName T>` or `template <typename T> requires ConceptName<T>`.
 */

// =========================================================================
// 7. Best Practices for Templates
// =========================================================================

/**
 * **7. Best Practices for Templates:**
 *
 * 7.1. **Keep it in Headers:** Generally, place template definitions (declarations and
 * definitions of member functions) entirely in header files (`.h` or `.hpp`).
 * This is because the compiler needs the full template definition to generate
 * instantiations for specific types.
 * (Exception: Explicit Instantiation, but that's for advanced scenarios/libraries)
 *
 * 7.2. **Clarity over Cleverness:** While templates can be used for complex TMP,
 * prioritize readability and maintainability. Simple, direct code is often better.
 *
 * 7.3. **Use Concepts (C++20):** Leverage C++20 Concepts to clearly specify template
 * requirements, improving error messages and code robustness.
 *
 * 7.4. **Minimize Template Parameters:** Only template on what needs to be generic.
 * Avoid templating on types that are fixed or can be handled otherwise.
 *
 * 7.5. **Error Handling in Templates:** For runtime errors, throw exceptions. For
 * compile-time errors, concepts are your best friend. `static_assert` can also
 * be used to enforce constraints at compile time.
 *
 * 7.6. **Documentation:** Document your templates thoroughly, explaining type requirements,
 * behavior, and examples.
 *
 * 7.7. **Prefer `std` Library Templates:** Before writing your own, check if `std::vector`,
 * `std::map`, `std::function`, `std::tuple`, `std::unique_ptr`, etc., meet your needs.
 * They are robust, optimized, and well-tested.
 */

// =========================================================================
// Main Function (Entry Point of the Program)
// =========================================================================

int main()
{
    std::cout << "--- C++ Templates Tutorial ---" << std::endl;

    demonstrateFunctionTemplates();
    demonstrateFunctionTemplateOverloading();
    demonstrateExplicitTemplateArguments();
    demonstrateClassTemplates();
    demonstrateDefaultTemplateArguments();
    demonstrateNonTypeTemplateParameters();
    demonstrateTemplateMetaprogramming();

    std::cout << "\n--- End of Tutorial ---" << std::endl;

    return 0;
}
