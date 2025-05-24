/**
 * File: 01-cpp-functions.cpp
 * Description: A comprehensive tutorial on functions in C++, covering their
 * definition, declaration, parameters, return types, overloading, default arguments,
 * scope, inline functions, and an introduction to recursion and function pointers.
 */

#include <iostream>  // Required for input/output operations (e.g., std::cout)
#include <string>    // Required for using std::string
#include <vector>    // Required for using std::vector

// =========================================================================
// 1. Introduction: What are Functions?
// =========================================================================

/**
 * **Introduction to C++ Functions:**
 * -   A function is a block of organized, reusable code that is used to perform
 * a single, related action.
 * -   Functions provide modularity for your program and a high degree of code reuse.
 * -   They allow you to break down complex problems into smaller, manageable pieces.
 * -   **Benefits:**
 * -   **Modularity:** Divides a program into smaller, easier-to-understand parts.
 * -   **Reusability:** Write code once and use it multiple times.
 * -   **Readability:** Improves the clarity and organization of your code.
 * -   **Debugging:** Easier to isolate and fix problems in smaller function units.
 */

// =========================================================================
// 2. Function Declaration (Prototype) vs. Definition
// =========================================================================

/**
 * **Function Declaration (Prototype):**
 * -   A function declaration (also known as a function prototype) tells the compiler
 * about a function's name, return type, and parameters *before* the function is defined.
 * -   It's like a "forward declaration" that allows you to call a function before
 * its full definition appears in the code.
 * -   Typically placed in header files (`.h` or `.hpp`) or at the top of a `.cpp` file
 * if the function is defined later in the same file.
 * -   Syntax: `returnType functionName(parameterType1 param1, parameterType2 param2, ...);`
 *
 * **Function Definition:**
 * -   The function definition provides the actual body of the function, containing
 * the code that performs the function's task.
 * -   Syntax:
 * ```cpp
 * returnType functionName(parameterType1 param1, parameterType2 param2, ...) {
 * // Function body (statements)
 * return someValue; // If returnType is not void
 * }
 * ```
 */

// Example 2.1: Function Declaration (Prototype)
int addNumbers(int a, int b);  // Declares the function 'addNumbers'

// Example 2.2: Function Definition (for a function called before its definition)
void greetUser(const std::string& name)
{  // Definition of greetUser
    std::cout << "2.2 Hello, " << name << "!" << std::endl;
}

// =========================================================================
// 3. Function Parameters and Arguments
// =========================================================================

/**
 * **Parameters:** Variables listed inside the parentheses in the function declaration/definition.
 * **Arguments:** The actual values passed to the function when it is called.
 *
 * **3.1. Pass by Value:**
 * -   A copy of the argument's value is passed to the function.
 * -   Changes made to the parameter inside the function do not affect the original argument.
 * -   This is the default behavior.
 */

// Example 3.1.1: Pass by Value
void incrementByValue(int num)
{
    num++;  // 'num' is a copy, original variable outside is not affected
    std::cout << "3.1.1 Inside incrementByValue: " << num << std::endl;
}

/**
 * **3.2. Pass by Reference:**
 * -   The function receives a reference (an alias) to the original argument.
 * -   Changes made to the parameter inside the function directly affect the original argument.
 * -   Uses the `&` operator in the parameter declaration.
 */

// Example 3.2.1: Pass by Reference
void incrementByReference(int& num)
{
    num++;  // 'num' is a reference, original variable outside IS affected
    std::cout << "3.2.1 Inside incrementByReference: " << num << std::endl;
}

/**
 * **3.3. Pass by Constant Reference (`const &`):**
 * -   The function receives a reference to the original argument, but it cannot modify the
 * argument.
 * -   Used for passing large objects efficiently without copying, while ensuring data integrity.
 * -   Combines efficiency of pass-by-reference with safety of pass-by-value.
 */

// Example 3.3.1: Pass by Constant Reference
void printStringLength(const std::string& str)
{
    // str[0] = 'X'; // This would cause a compilation error: cannot modify a const reference
    std::cout << "3.3.1 Length of string: " << str.length() << std::endl;
}

// =========================================================================
// 4. Return Types
// =========================================================================

/**
 * **Return Types:**
 * -   A function can return a single value to the calling code.
 * -   The `returnType` specifies the data type of the value the function will send back.
 * -   **`void`:** If a function does not return any value, its return type is `void`.
 * -   **`return` statement:** Used to send a value back from the function.
 * Execution of the function terminates immediately after the `return` statement.
 */

// Example 4.1: Function returning an int
int multiply(int a, int b)
{
    return a * b;  // Returns the product of a and b
}

// Example 4.2: Function returning void
void printMessage(const std::string& msg)
{
    std::cout << "4.2 Message: " << msg << std::endl;
    // No return statement needed for void functions, or 'return;' can be used.
}

// Example 4.3: Function returning a reference (advanced, use with care)
int& getLargest(int& x, int& y)
{
    return (x > y) ? x : y;
}

// =========================================================================
// 5. Function Overloading
// =========================================================================

/**
 * **Function Overloading:**
 * -   Allows you to define multiple functions with the **same name** but different
 * parameter lists (different number of parameters, different types of parameters, or different
 * order of parameters).
 * -   The compiler determines which overloaded function to call based on the arguments
 * provided during the function call.
 * -   Return type alone is NOT sufficient to overload a function.
 */

// Example 5.1: Overloaded functions
int operate(int a, int b)
{
    std::cout << "5.1 Calling int operate(int, int)" << std::endl;
    return a + b;
}

double operate(double a, double b)
{
    std::cout << "5.1 Calling double operate(double, double)" << std::endl;
    return a * b;
}

std::string operate(const std::string& s1, const std::string& s2)
{
    std::cout << "5.1 Calling string operate(string, string)" << std::endl;
    return s1 + s2;
}

// Example 5.2: Overloading with different number of arguments
void print(int val)
{
    std::cout << "5.2 Integer: " << val << std::endl;
}

void print(int val1, int val2)
{
    std::cout << "5.2 Two Integers: " << val1 << ", " << val2 << std::endl;
}

// =========================================================================
// 6. Default Arguments
// =========================================================================

/**
 * **Default Arguments:**
 * -   Allow you to specify a default value for a function parameter.
 * -   If the caller doesn't provide an argument for that parameter, the default value is used.
 * -   Default arguments must be placed at the **end** of the parameter list.
 * -   They should only be specified in the **function declaration (prototype)**, not in the
 * definition.
 */

// Example 6.1: Function with default arguments
void displayVolume(double length, double width = 1.0, double height = 1.0);  // Declaration only

// =========================================================================
// 7. Scope of Variables within Functions
// =========================================================================

/**
 * **Scope:** Refers to the region of a program where a variable can be accessed.
 *
 * **7.1. Local Variables:**
 * -   Declared inside a function (or a block within a function).
 * -   Exist only within that function/block.
 * -   Cannot be accessed from outside the function/block.
 * -   Are created when the function is called and destroyed when it exits.
 *
 * **7.2. Global Variables:**
 * -   Declared outside any function, usually at the top of the file.
 * -   Can be accessed from anywhere in the program.
 * -   Generally discouraged due to potential for unintended side effects and reduced modularity.
 */

// Example 7.1: Local and Global Variables
int globalVar = 100;  // Global variable

void functionScopeExample()
{
    int localVar = 50;  // Local variable
    std::cout << "7.1 Inside function: globalVar = " << globalVar << ", localVar = " << localVar
              << std::endl;
    // std::cout << otherVar << std::endl; // Error: otherVar is not in scope
}

// =========================================================================
// 8. Inline Functions
// =========================================================================

/**
 * **Inline Functions:**
 * -   A hint to the compiler to replace the function call with the actual function code
 * at compile time (known as "inlining").
 * -   Can improve performance by avoiding function call overhead, especially for small,
 * frequently called functions.
 * -   The `inline` keyword is a *suggestion* to the compiler, not a command. The compiler
 * may choose to ignore it.
 * -   Overuse can lead to "code bloat" (larger executable size).
 */

// Example 8.1: Inline function
inline int square(int x)
{
    return x * x;
}

// =========================================================================
// 9. Recursion (Brief Introduction)
// =========================================================================

/**
 * **Recursion:**
 * -   A function that calls itself, either directly or indirectly.
 * -   Used to solve problems that can be broken down into smaller, self-similar subproblems.
 * -   Requires a **base case** to stop the recursion and prevent infinite loops.
 */

// Example 9.1: Factorial using recursion
long long factorial(int n)
{
    if (n == 0 || n == 1)
    {  // Base case
        return 1;
    }
    else
    {
        return n * factorial(n - 1);  // Recursive call
    }
}

// =========================================================================
// 10. Pointers to Functions (Brief Introduction)
// =========================================================================

/**
 * **Pointers to Functions:**
 * -   In C++, functions themselves have addresses, and you can store these addresses
 * in function pointers.
 * -   Allows you to pass functions as arguments to other functions, store them in
 * data structures, or call them dynamically.
 * -   Useful for implementing callbacks, strategy patterns, or command patterns.
 */

// Example 10.1: Function pointer
int subtractNumbers(int a, int b)
{
    return a - b;
}

// Function that takes a function pointer as an argument
void performOperation(int x, int y, int (*operationFunc)(int, int))
{
    int result = operationFunc(x, y);
    std::cout << "10.1 Operation Result: " << result << std::endl;
}

// =========================================================================
// Main Function (Entry Point of the Program)
// =========================================================================

int main()
{
    // --- Demonstrating Section 2: Function Declaration & Definition ---
    std::cout << "--- Section 2: Function Declaration & Definition ---" << std::endl;
    greetUser("Alice");          // Call to defined function
    int sum = addNumbers(5, 7);  // Call to declared function
    std::cout << "2.1 Sum of 5 and 7: " << sum << std::endl;

    // --- Demonstrating Section 3: Function Parameters ---
    std::cout << "\n--- Section 3: Function Parameters ---" << std::endl;
    int val = 10;
    std::cout << "3.1.1 Before incrementByValue: " << val << std::endl;  // 10
    incrementByValue(val);
    std::cout << "3.1.1 After incrementByValue: " << val << std::endl;  // Still 10

    int refVal = 20;
    std::cout << "3.2.1 Before incrementByReference: " << refVal << std::endl;  // 20
    incrementByReference(refVal);
    std::cout << "3.2.1 After incrementByReference: " << refVal << std::endl;  // 21

    std::string myStr = "C++ Programming";
    printStringLength(myStr);

    // --- Demonstrating Section 4: Return Types ---
    std::cout << "\n--- Section 4: Return Types ---" << std::endl;
    int product = multiply(8, 4);
    std::cout << "4.1 Product of 8 and 4: " << product << std::endl;  // 32
    printMessage("Hello from printMessage!");

    int a = 10, b = 20;
    int& largest = getLargest(a, b);  // largest is now a reference to 'b'
    std::cout << "4.3 Largest of 10 and 20: " << largest << std::endl;  // 20
    largest = 25;  // Modifies 'b' because 'largest' is a reference
    std::cout << "4.3 After modifying largest, b is: " << b << std::endl;  // 25

    // --- Demonstrating Section 5: Function Overloading ---
    std::cout << "\n--- Section 5: Function Overloading ---" << std::endl;
    std::cout << "Result (int): " << operate(10, 5) << std::endl;
    std::cout << "Result (double): " << operate(10.5, 2.0) << std::endl;
    std::cout << "Result (string): " << operate("Hello", " World") << std::endl;
    print(100);
    print(10, 20);

    // --- Demonstrating Section 6: Default Arguments ---
    std::cout << "\n--- Section 6: Default Arguments ---" << std::endl;
    displayVolume(5.0);            // Uses default width=1.0, height=1.0
    displayVolume(5.0, 2.0);       // Uses default height=1.0
    displayVolume(5.0, 2.0, 3.0);  // All arguments provided

    // --- Demonstrating Section 7: Scope of Variables ---
    std::cout << "\n--- Section 7: Scope of Variables ---" << std::endl;
    functionScopeExample();
    std::cout << "7.1 Outside function: globalVar = " << globalVar << std::endl;
    // std::cout << localVar << std::endl; // Error: localVar is not in scope

    // --- Demonstrating Section 8: Inline Functions ---
    std::cout << "\n--- Section 8: Inline Functions ---" << std::endl;
    int s = square(7);
    std::cout << "8.1 Square of 7: " << s << std::endl;  // 49

    // --- Demonstrating Section 9: Recursion ---
    std::cout << "\n--- Section 9: Recursion ---" << std::endl;
    std::cout << "9.1 Factorial of 5: " << factorial(5) << std::endl;  // 120

    // --- Demonstrating Section 10: Pointers to Functions ---
    std::cout << "\n--- Section 10: Pointers to Functions ---" << std::endl;
    performOperation(30, 10, subtractNumbers);  // Pass subtractNumbers function
    performOperation(5, 7, addNumbers);         // Pass addNumbers function

    return 0;  // Indicate successful program execution
}

// =========================================================================
// Function Definitions (for declared functions)
// =========================================================================

// Definition of addNumbers (declared earlier)
int addNumbers(int a, int b)
{
    return a + b;
}

// Definition of displayVolume (declared earlier)
void displayVolume(double length, double width, double height)
{
    std::cout << "6.1 Volume: " << length * width * height << std::endl;
}
