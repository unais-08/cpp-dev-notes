/**
 * File: 01-cpp-references.cpp
 * Description: A comprehensive tutorial on references in C++, explaining their
 * nature as aliases, declaration, initialization, use in functions (pass by reference,
 * return by reference), const references, key differences from pointers,
 * and common pitfalls.
 * Date: 2025-05-23
 */

#include <iostream>  // For std::cout, std::endl
#include <string>    // For std::string
#include <vector>    // For std::vector (to show passing large objects)

// =========================================================================
// 1. Introduction: What are References?
// =========================================================================

/**
 * **1. Introduction: What are References?**
 * -   In C++, a **reference** is an **alias** (another name) for an existing variable.
 * -   Once a reference is initialized to a variable, it acts exactly like that variable.
 * Any operation performed on the reference is actually performed on the original variable.
 * -   Think of it like giving a person a nickname. Both the real name and the nickname
 * refer to the same person.
 * -   **Key Uses:**
 * -   **Pass by Reference:** The most common use, allowing functions to modify original
 * arguments without using pointers and their dereferencing syntax. Also, efficient
 * for passing large objects.
 * -   **Return by Reference:** Allows a function to return a reference to a variable,
 * enabling modification of the original.
 * -   **Range-based for loops:** Used implicitly for iteration.
 */

// =========================================================================
// 2. Declaration and Initialization
// =========================================================================

/**
 * **2. Declaration and Initialization:**
 * -   **Syntax:** `dataType& referenceName = existingVariable;`
 * -   The `&` symbol indicates a reference. It's placed after the type, before the name, or in
 * between.
 * -   **Crucial Rule:** A reference **MUST be initialized** at the time of declaration.
 * It cannot be declared without an initializer.
 * -   Once initialized, a reference **cannot be reseated** (made to refer to a different variable).
 * It will always refer to the variable it was originally initialized to.
 */

// Example 2.1.1: Basic reference declaration and usage
void demonstrateBasicReference()
{
    int score = 100;
    int& refScore = score;  // refScore is now an alias for 'score'

    std::cout << "--- 2. Basic Reference Example ---" << std::endl;
    std::cout << "Original score: " << score << std::endl;         // Output: 100
    std::cout << "Reference refScore: " << refScore << std::endl;  // Output: 100

    refScore = 200;  // Modifying refScore actually modifies 'score'
    std::cout << "Score after modifying refScore: " << score << std::endl;  // Output: 200

    score = 300;  // Modifying score also affects refScore
    std::cout << "RefScore after modifying score: " << refScore << std::endl;  // Output: 300

    // Getting addresses to prove they are the same
    std::cout << "Address of score: " << &score << std::endl;
    std::cout << "Address of refScore: " << &refScore << std::endl;  // Same address!

    // int& uninitializedRef; // ERROR: References must be initialized
    // int anotherVal = 400;
    // refScore = anotherVal; // This is assignment, NOT reseating. It changes score to 400, not
    // makes refScore refer to anotherVal. std::cout << "Score after attempted 'reseating': " <<
    // score << std::endl; // Output: 400 std::cout << "Address of anotherVal: " << &anotherVal <<
    // std::endl; // Different address std::cout << "Address of refScore (still same as score): " <<
    // &refScore << std::endl; // Still same as score
}

// =========================================================================
// 3. Lvalue References
// =========================================================================

/**
 * **3. Lvalue References:**
 * -   The type of reference discussed so far is an "lvalue reference."
 * -   An "lvalue" is an expression that identifies a memory location (e.g., a variable name).
 * -   Lvalue references typically bind only to lvalues.
 *
 * **3.1. References as Function Parameters (Pass by Reference):**
 * -   This is one of the most common and powerful uses of references.
 * -   Allows a function to directly access and modify the original argument passed from the caller.
 * -   Avoids the overhead of copying large objects (unlike pass by value).
 * -   Often preferred over passing by pointer when the parameter is guaranteed to exist and not be
 * null.
 */

// Example 3.1.1: Modifying a variable using pass by reference
void increment(int& num)
{           // 'num' is a reference to the original variable
    num++;  // Modifies the original variable
    std::cout << "3.1.1 Inside increment: " << num << std::endl;
}

// Example 3.1.2: Swapping values using pass by reference
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Example 3.1.3: Passing large objects efficiently by reference
void processVector(std::vector<int>& vec)
{  // Reference to avoid copying the whole vector
    if (!vec.empty())
    {
        vec[0] = 999;  // Modifies the original vector
    }
    std::cout << "3.1.3 Inside processVector, first element: " << vec[0] << std::endl;
}

/**
 * **3.2. References as Return Values:**
 * -   A function can return a reference to a variable.
 * -   This allows the caller to modify the original variable that the function returned a reference
 * to.
 * -   **CRITICAL CAUTION:** Never return a reference to a **local variable** declared inside the
 * function. Local variables are destroyed when the function exits, making the returned reference a
 * **dangling reference** (it refers to invalid, freed memory).
 * -   It's safe to return references to:
 * -   Parameters that were passed by reference (if their lifetime extends beyond the function
 * call).
 * -   Static variables.
 * -   Members of objects that persist beyond the function call.
 */

// Example 3.2.1: DANGEROUS - Returning reference to local variable
// int& getLocalValue() {
//     int localVal = 100;
//     return localVal; // DANGER! localVal goes out of scope and is destroyed here.
// }

// Example 3.2.2: Safe - Returning reference to a static variable
int& getStaticCounter()
{
    static int counter = 0;  // Static variable persists throughout program execution
    counter++;
    return counter;
}

// Example 3.2.3: Safe - Returning reference to an element of an array/vector (assuming it lives
// long enough)
int& getVectorElement(std::vector<int>& v, int index)
{
    return v.at(index);  // .at() provides bounds checking
}

// =========================================================================
// 4. `const` References
// =========================================================================

/**
 * **4. `const` References (`const dataType& referenceName = ...;`)**
 * -   A `const` reference allows you to create an alias to a variable, but you
 * cannot modify the original variable through this alias.
 * -   **Key Advantages:**
 * -   **Safety:** Guarantees that the referenced variable will not be changed.
 * -   **Efficiency:** Still avoids copying large objects when passing to functions.
 * -   **Flexibility:** Can bind to `const` objects, non-`const` objects, and even **rvalues**
 * (temporary values or literals).
 */

// Example 4.1.1: const reference to prevent modification
void printValue(const int& num)
{
    // num++; // ERROR: cannot modify through a const reference
    std::cout << "4.1.1 Value via const reference: " << num << std::endl;
}

// Example 4.1.2: const reference binding to temporaries/rvalues
void processConstString(const std::string& s)
{
    std::cout << "4.1.2 Processing string: " << s << ", length: " << s.length() << std::endl;
}

// =========================================================================
// 5. References vs. Pointers
// =========================================================================

/**
 * **5. References vs. Pointers: Key Differences**
 *
 * | Feature            | Reference (`&`)                                  | Pointer (`*`) | |
 * :----------------- | :----------------------------------------------- |
 * :----------------------------------------------- | | **Initialization** | Must be initialized at
 * declaration.              | Can be declared uninitialized (wild pointer - DANGER!). | |
 * **Nullability** | Cannot be null (must refer to a valid object).   | Can be `nullptr` (or `NULL`
 * or `0`).           | | **Reseating** | Cannot be reseated; always refers to original.   | Can be
 * reseated (made to point to another object). | | **Dereferencing** | No explicit dereference
 * operator needed (`*`).   | Requires explicit dereference operator (`*`).     | | **Arithmetic** |
 * No direct arithmetic operations.                 | Supports arithmetic operations (`++`, `--`,
 * `+`, `-`). | | **Syntax** | Cleaner, more like using the original variable.  | Explicit `*` and
 * `&` operators can make code verbose. | | **Memory** | Not generally considered a separate object
 * with its own address, but compiler may optimize. | Always has its own memory address. | |
 * **Ownership** | Does not imply ownership.                        | Can imply ownership (with
 * `new`/`delete` or smart pointers). |
 *
 * **When to Use Which:**
 * -   **Use References:**
 * -   When you need an alias for an existing object.
 * -   For pass by reference parameters to avoid copying and/or to modify the original object.
 * -   When you are sure the target object always exists (never null).
 * -   For operator overloading (e.g., `operator[]`, `operator=`).
 * -   **Use Pointers:**
 * -   When you need to perform dynamic memory allocation (`new`/`delete` or smart pointers).
 * -   When the target object might be null (e.g., optional parameters).
 * -   When you need to reassign the pointer to point to different objects.
 * -   When you need pointer arithmetic (e.g., iterating through raw memory/arrays).
 * -   When implementing complex data structures like linked lists.
 */

// Example 5.1: Demonstrating differences
void comparePointersAndReferences()
{
    int value = 10;
    int& ref = value;   // Reference to 'value'
    int* ptr = &value;  // Pointer to 'value'

    std::cout << "\n--- 5. References vs. Pointers Example ---" << std::endl;
    std::cout << "Value: " << value << std::endl;
    std::cout << "Reference (ref): " << ref << ", Address: " << &ref << std::endl;
    std::cout << "Pointer (ptr): " << ptr << ", Dereferenced (*ptr): " << *ptr
              << ", Address: " << &ptr << std::endl;

    // Reseating
    int anotherValue = 20;
    // ref = anotherValue; // This assigns 20 to 'value', doesn't make 'ref' point to 'anotherValue'
    ptr = &anotherValue;  // Pointer can be reseated
    std::cout << "After ptr reseated to anotherValue: " << *ptr << std::endl;
}

// =========================================================================
// 6. Rvalue References (C++11 onwards - Brief Introduction)
// =========================================================================

/**
 * **6. Rvalue References (C++11 onwards - Brief Introduction)**
 * -   Introduced in C++11, rvalue references (`&&`) are used primarily for
 * **move semantics** and **perfect forwarding**.
 * -   An "rvalue" is an expression that does not identify a memory location
 * (e.g., temporary objects, literals like `10`, results of expressions like `a + b`).
 * -   They allow you to "steal" resources from temporary objects, improving performance
 * by avoiding unnecessary copies.
 * -   This is an advanced topic, but it's important to know `&&` is not just "reference to a
 * reference."
 */

// Example 6.1: Basic Rvalue Reference concept
void processRvalue(int&& tempVal)
{  // tempVal is an rvalue reference
    std::cout << "6.1 Processing rvalue: " << tempVal << std::endl;
    // tempVal can be modified here because it's a "named rvalue reference", which behaves like an
    // lvalue. However, it's typically used for moving resources.
}

// =========================================================================
// 7. Common Pitfalls with References
// =========================================================================

/**
 * **7. Common Pitfalls with References:**
 *
 * 7.1. **Uninitialized References:**
 * -   References *must* be initialized. Failing to do so is a compile-time error.
 *
 * 7.2. **Dangling References:**
 * -   A reference that refers to memory that has been deallocated or no longer exists.
 * -   Most commonly occurs when returning a reference to a local variable that goes
 * out of scope after the function returns.
 * -   Using a dangling reference leads to **undefined behavior** (crashes, corrupt data).
 */

// Example 7.1: Dangling Reference (Illustrative - don't run as it's UB)
// int& danglingReferenceExample() {
//     int local = 10;
//     return local; // Returns reference to 'local' which is about to be destroyed
// }

// void runDanglingReferenceExample() {
//     int& ref = danglingReferenceExample(); // ref now refers to invalid memory
//     std::cout << ref << std::endl; // DANGER! Undefined behavior
// }

/**
 * 7.3. **References to Null:**
 * -   References cannot be null. Attempting to bind a reference to a null pointer
 * is undefined behavior. You should always ensure the variable you are referencing is valid.
 */

// =========================================================================
// 8. Best Practices for References
// =========================================================================

/**
 * **8. Best Practices for References:**
 *
 * 8.1. **Prefer `const&` for Input Parameters:**
 * -   When passing large objects to functions that don't need to modify the original object,
 * use `const dataType&` to avoid copying and ensure data integrity. This is very common.
 *
 * 8.2. **Use `&` for Output Parameters:**
 * -   When a function needs to modify an argument, use `dataType&`.
 *
 * 8.3. **Avoid Returning References to Local Variables:**
 * -   This is a critical rule to prevent dangling references. Only return references to variables
 * whose lifetime extends beyond the function call (e.g., static variables, dynamically allocated
 * memory, or members of objects passed by reference).
 *
 * 8.4. **Favor References over Pointers when Nullability is Not an Issue:**
 * -   If a parameter or return value is guaranteed to always refer to a valid object, references
 * are often preferred for their cleaner syntax and compile-time safety (non-null, non-reseatable).
 *
 * 8.5. **Understand the "Alias" Concept:**
 * -   Always remember that a reference is literally another name for the same piece of memory.
 * Any change through the reference is a change to the original.
 */

// =========================================================================
// Main Function (Entry Point of the Program)
// =========================================================================

int main()
{
    demonstrateBasicReference();

    std::cout << "\n--- 3.1. References as Function Parameters ---" << std::endl;
    int myValue = 5;
    std::cout << "Before increment: " << myValue << std::endl;
    increment(myValue);                                        // Pass by reference
    std::cout << "After increment: " << myValue << std::endl;  // myValue is now 6

    int x = 10, y = 20;
    std::cout << "Before swap: x=" << x << ", y=" << y << std::endl;
    swap(x, y);                                                      // Pass by reference
    std::cout << "After swap: x=" << x << ", y=" << y << std::endl;  // x=20, y=10

    std::vector<int> myVec = {10, 20, 30};
    std::cout << "Before processVector, first element: " << myVec[0] << std::endl;
    processVector(myVec);
    std::cout << "After processVector, first element: " << myVec[0]
              << std::endl;  // myVec[0] is now 999

    std::cout << "\n--- 3.2. References as Return Values ---" << std::endl;
    std::cout << "Static counter initial: " << getStaticCounter()
              << std::endl;    // Returns 1 (counter was 0, now 1)
    getStaticCounter() = 500;  // Modifies the static counter via reference
    std::cout << "Static counter after modification: " << getStaticCounter()
              << std::endl;  // Returns 501

    std::vector<int> dataVec = {10, 20, 30};
    std::cout << "Original dataVec[1]: " << dataVec[1] << std::endl;
    getVectorElement(dataVec, 1) = 77;  // Modify dataVec[1] via returned reference
    std::cout << "Modified dataVec[1]: " << dataVec[1] << std::endl;

    std::cout << "\n--- 4. Const References ---" << std::endl;
    int constVal = 10;
    printValue(constVal);      // Binds to lvalue
    printValue(20);            // Binds to rvalue (temporary)
    printValue(constVal + 5);  // Binds to rvalue (result of expression)

    processConstString("Temporary string literal");  // Binds to rvalue
    std::string existingString = "Existing String";
    processConstString(existingString);  // Binds to lvalue

    comparePointersAndReferences();

    std::cout << "\n--- 6. Rvalue References (Brief) ---" << std::endl;
    processRvalue(42);  // Binds to an rvalue
    // int lval = 10;
    // processRvalue(lval); // ERROR: cannot bind rvalue reference to lvalue

    // runDanglingReferenceExample(); // WARNING: Uncommenting this may cause a crash due to UB

    std::cout << "\n--- End of Tutorial ---" << std::endl;

    return 0;
}
