/**
 * File: 02-cpp-functions-advanced.cpp
 * Description: A detailed tutorial on advanced concepts and modern features of C++ functions,
 * including in-depth coverage of function pointers, lambda expressions, function objects,
 * variadic templates, and function specifiers.
 * Date: 2025-05-23
 */

#include <iostream>   // For std::cout, std::endl
#include <string>     // For std::string
#include <vector>     // For std::vector
#include <functional> // For std::function (modern C++ function pointers)
#include <numeric>    // For std::accumulate

// =========================================================================
// 1. Function Pointers: Deeper Dive
// =========================================================================

/**
 * **1. Function Pointers: Deeper Dive**
 * -   A function pointer is a variable that stores the memory address of a function.
 * -   It allows you to refer to functions, pass them as arguments, return them from
 * other functions, and store them in data structures.
 * -   **Syntax:** `return_type (*pointer_name)(parameter_list);`
 * -   The parentheses around `*pointer_name` are crucial to distinguish it from a
 * function declaration.
 * -   The parameter list in the pointer declaration must match the function signature.
 */

// Example 1.1: Declaring and using a function pointer
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

// Function that takes a function pointer as an argument (callback pattern)
void calculateAndPrint(int x, int y, int (*operation)(int, int))
{
    int result = operation(x, y);
    std::cout << "1.1 Result of operation: " << result << std::endl;
}

// Example 1.2: Array of function pointers
typedef int (*MathOperation)(int, int); // Using typedef for readability

// Example 1.3: Returning a function pointer (e.g., a factory for operations)
MathOperation getOperation(char op_char)
{
    if (op_char == '+')
    {
        return add;
    }
    else if (op_char == '-')
    {
        return subtract;
    }
    return nullptr; // Return null for unsupported operations
}

// =========================================================================
// 2. Lambda Expressions (C++11 onwards)
// =========================================================================

/**
 * **2. Lambda Expressions (Anonymous Functions)**
 * -   Introduced in C++11, lambdas are concise ways to define anonymous (unnamed)
 * function objects directly where they are needed.
 * -   They are essentially inline functions that can capture variables from their
 * surrounding scope.
 * -   **Syntax:** `[capture_list](parameters) -> return_type { function_body }`
 * -   `capture_list`: Specifies which variables from the enclosing scope are accessible.
 * -   `parameters`: Function parameters.
 * -   `return_type`: Optional, compiler can often deduce.
 * -   `function_body`: The code to be executed.
 */

/**
 * **2.1. Capture List:**
 * -   `[]`: No variables captured. The lambda can only access its parameters or global variables.
 * -   `[=]`: Capture by value. All variables used in the lambda's body from the enclosing scope
 * are copied into the lambda. Changes to these copies inside the lambda do not affect originals.
 * -   `[&]`: Capture by reference. All variables used from the enclosing scope are referenced.
 * Changes inside the lambda affect the original variables.
 * -   `[var_name]`: Capture `var_name` by value.
 * -   `[&var_name]`: Capture `var_name` by reference.
 * -   `[this]`: Capture the `this` pointer by value (for member functions).
 */

// Example 2.1: Basic Lambda Usage
void performLambdaOperations()
{
    int x = 10;
    int y = 5;

    // Lambda with no capture
    auto sum_lambda = [](int a, int b)
    { return a + b; };
    std::cout << "2.1 Lambda sum (no capture): " << sum_lambda(x, y) << std::endl;

    // Lambda capturing by value
    auto multiply_lambda = [x, y](int factor)
    { return (x * y) * factor; };
    std::cout << "2.1 Lambda multiply (capture by value): " << multiply_lambda(2) << std::endl;
    x = 20;                                                                                    // Changing x won't affect multiply_lambda's captured x
    std::cout << "2.1 Lambda multiply (after x changed): " << multiply_lambda(2) << std::endl; // Still uses original x=10

    // Lambda capturing by reference
    int counter = 0;
    auto increment_lambda = [&counter]()
    { counter++; };
    increment_lambda();
    increment_lambda();
    std::cout << "2.1 Lambda increment (capture by reference): " << counter << std::endl; // counter is 2

    // Lambda with explicit return type and mutable keyword (for modifying captured by value)
    auto mutable_lambda = [val = 10]() mutable { // val is captured by value, but can be modified internally
        val++;
        return val;
    };
    std::cout << "2.1 Mutable lambda: " << mutable_lambda() << std::endl; // 11
    std::cout << "2.1 Mutable lambda: " << mutable_lambda() << std::endl; // 12
}

// Example 2.2: Lambdas with Standard Library Algorithms
void processVectorWithLambda()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> squared_numbers;

    // Use lambda with std::for_each
    std::for_each(numbers.begin(), numbers.end(), [](int n)
                  { std::cout << n << " "; });
    std::cout << std::endl;

    // Use lambda with std::transform
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squared_numbers),
                   [](int n)
                   { return n * n; });

    std::cout << "2.2 Squared numbers: ";
    for (int n : squared_numbers)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// =========================================================================
// 3. Function Objects (Functors)
// =========================================================================

/**
 * **3. Function Objects (Functors)**
 * -   A function object (or functor) is an instance of a class that overloads the
 * `operator()`.
 * -   This allows objects of that class to be called like functions.
 * -   Functors can maintain state (member variables), making them more powerful
 * than simple function pointers for certain tasks.
 * -   Lambdas are essentially syntactic sugar for creating simple function objects.
 */

// Example 3.1: Basic Functor
class Multiplier
{
public:
    int factor; // State of the functor

    Multiplier(int f) : factor(f) {} // Constructor

    // Overload the function call operator
    int operator()(int num) const
    {
        return num * factor;
    }
};

// Example 3.2: Functor with more complex state
class Accumulator
{
private:
    int current_sum;

public:
    Accumulator() : current_sum(0) {}

    void operator()(int val)
    {
        current_sum += val;
        std::cout << "3.2 Current sum: " << current_sum << std::endl;
    }
    int getSum() const { return current_sum; }
};

// =========================================================================
// 4. Variadic Functions (C-style) and Variadic Templates (Modern C++)
// =========================================================================

/**
 * **4. Variadic Functions (C-style) and Variadic Templates (Modern C++)**
 * -   Allow functions to accept a variable number of arguments.
 *
 * **4.1. C-style Variadic Functions (`...` and `<cstdarg>`)**
 * -   Inherited from C. Use `...` in parameter list.
 * -   Require `<cstdarg>` for `va_list`, `va_start`, `va_arg`, `va_end`.
 * -   **Type-unsafe:** No compile-time type checking for the variable arguments.
 * -   **Generally discouraged in modern C++** in favor of variadic templates or `std::initializer_list`.
 */

// Example 4.1: C-style variadic sum (for demonstration, not recommended)
#include <cstdarg>
double sum_c_style(int count, ...)
{
    double total = 0.0;
    va_list args;
    va_start(args, count); // Initialize va_list
    for (int i = 0; i < count; ++i)
    {
        total += va_arg(args, double); // Retrieve argument (must specify type)
    }
    va_end(args); // Clean up va_list
    return total;
}

/**
 * **4.2. Variadic Templates (C++11 onwards)**
 * -   A modern, type-safe way to handle a variable number of arguments.
 * -   Uses template parameter packs (`typename... Args`).
 * -   Requires recursion or fold expressions (C++17) to process the arguments.
 */

// Example 4.2: Variadic Template Sum (recursive approach)
template <typename T>
T sum_variadic(T t)
{ // Base case for recursion
    return t;
}

template <typename T, typename... Args>
T sum_variadic(T first, Args... rest)
{ // Recursive case
    return first + sum_variadic(rest...);
}

// Example 4.3: Variadic Template with Fold Expressions (C++17 onwards)
template <typename... Args>
auto sum_fold_expression(Args... args)
{
    return (args + ...); // Fold expression: sums all arguments
}

// =========================================================================
// 5. Function Specifiers: `noexcept` and `constexpr`
// =========================================================================

/**
 * **5. Function Specifiers:**
 *
 * **5.1. `noexcept` (C++11 onwards)**
 * -   Indicates that a function (or lambda) is guaranteed not to throw any exceptions.
 * -   **Purpose:** Primarily for compiler optimization. If a function is marked `noexcept`
 * and it *does* throw an exception, the program will terminate via `std::terminate()`.
 * -   Useful for low-level code where exception safety is critical or for functions
 * that truly cannot fail by throwing.
 * -   Syntax: `return_type functionName(params) noexcept { ... }`
 */

// Example 5.1: noexcept function
void safeOperation() noexcept
{
    // This function guarantees not to throw exceptions.
    // If it did, std::terminate() would be called.
    std::cout << "5.1 Safe operation completed (noexcept)." << std::endl;
}

/**
 * **5.2. `constexpr` (C++11 onwards)**
 * -   Indicates that a function (or lambda, or variable) can be evaluated at **compile time**.
 * -   **Purpose:** Allows computations to be performed during compilation, resulting in
 * faster runtime execution and enabling use in contexts that require compile-time constants
 * (e.g., array sizes, template arguments).
 * -   `constexpr` functions must have a very simple body (e.g., single `return` statement,
 * no side effects, no dynamic memory allocation, etc. - rules relaxed in C++14/17/20).
 * -   If a `constexpr` function *can* be evaluated at compile time, it *will* be.
 * If not, it falls back to runtime evaluation.
 */

// Example 5.2: constexpr function
constexpr int getSquare(int n)
{
    return n * n;
}

// =========================================================================
// 6. Overload Resolution Rules (Brief Overview)
// =========================================================================

/**
 * **6. Overload Resolution Rules:**
 * -   When you call an overloaded function, the C++ compiler follows a strict set of rules
 * to determine which specific overload to invoke. This process is called "overload resolution."
 * -   The compiler tries to find the "best match" among the available overloaded functions.
 * -   **General Order of Preference:**
 * 1.  **Exact Match:** An overload whose parameters exactly match the types of the arguments.
 * 2.  **Promotion:** Arguments can be promoted (e.g., `char` to `int`, `float` to `double`).
 * 3.  **Standard Conversions:** Arguments can be converted (e.g., `int` to `double`, `double` to `int`, `Derived*` to `Base*`).
 * 4.  **User-defined Conversions:** Conversions defined by constructors or conversion operators.
 * 5.  **Ellipsis (`...`):** C-style variadic functions are the lowest priority.
 * -   If multiple overloads are equally good matches, it results in an **ambiguity error**.
 */

// Example 6.1: Overload Resolution
void process(int i) { std::cout << "6.1 Processing int: " << i << std::endl; }
void process(double d) { std::cout << "6.1 Processing double: " << d << std::endl; }
void process(char c) { std::cout << "6.1 Processing char: " << c << std::endl; }

// =========================================================================
// Main Function (Entry Point of the Program)
// =========================================================================

int main()
{
    std::cout << "--- Section 1: Function Pointers ---" << std::endl;
    int (*funcPtr)(int, int);                                                               // Declare a function pointer
    funcPtr = add;                                                                          // Assign the address of the 'add' function
    std::cout << "1.1 Using function pointer (add): " << funcPtr(10, 20) << std::endl;      // Calls add(10, 20)
    funcPtr = subtract;                                                                     // Assign the address of the 'subtract' function
    std::cout << "1.1 Using function pointer (subtract): " << funcPtr(10, 20) << std::endl; // Calls subtract(10, 20)

    calculateAndPrint(25, 15, add);      // Pass 'add' function
    calculateAndPrint(25, 15, subtract); // Pass 'subtract' function

    MathOperation ops[] = {add, subtract}; // Array of function pointers
    std::cout << "1.2 Using array of function pointers (add): " << ops[0](5, 3) << std::endl;
    std::cout << "1.2 Using array of function pointers (subtract): " << ops[1](5, 3) << std::endl;

    MathOperation chosenOp = getOperation('+');
    if (chosenOp)
    {
        std::cout << "1.3 Chosen operation ('+'): " << chosenOp(7, 3) << std::endl;
    }
    chosenOp = getOperation('*'); // Unsupported
    if (!chosenOp)
    {
        std::cout << "1.3 Chosen operation ('*'): Unsupported." << std::endl;
    }

    std::cout << "\n--- Section 2: Lambda Expressions ---" << std::endl;
    performLambdaOperations();
    processVectorWithLambda();

    std::cout << "\n--- Section 3: Function Objects (Functors) ---" << std::endl;
    Multiplier multiplyBy3(3);
    std::cout << "3.1 Multiplier by 3: " << multiplyBy3(7) << std::endl; // Calls operator()(7)

    Accumulator acc;
    acc(10); // Calls operator()(10)
    acc(20); // Calls operator()(20)
    std::cout << "3.2 Final accumulated sum: " << acc.getSum() << std::endl;

    std::cout << "\n--- Section 4: Variadic Functions/Templates ---" << std::endl;
    std::cout << "4.1 C-style variadic sum (double): " << sum_c_style(3, 1.1, 2.2, 3.3) << std::endl;
    std::cout << "4.2 Variadic template sum (recursive): " << sum_variadic(1, 2, 3, 4, 5) << std::endl;
    std::cout << "4.3 Variadic template sum (fold expression): " << sum_fold_expression(10, 20, 30) << std::endl;
    std::cout << "4.3 Variadic template sum (mixed types, fold expression): " << sum_fold_expression(1.5, 2, 3.0) << std::endl;

    std::cout << "\n--- Section 5: Function Specifiers ---" << std::endl;
    safeOperation();
    // Using constexpr function
    constexpr int compileTimeSquare = getSquare(10); // Evaluated at compile time
    std::cout << "5.2 Compile-time square of 10: " << compileTimeSquare << std::endl;
    int runtimeVal = 7;
    int runtimeSquare = getSquare(runtimeVal); // Evaluated at runtime
    std::cout << "5.2 Runtime square of 7: " << runtimeSquare << std::endl;

    std::cout << "\n--- Section 6: Overload Resolution ---" << std::endl;
    process(5);   // Calls process(int)
    process(5.5); // Calls process(double)
    process('A'); // Calls process(char) - char promotes to int if char overload not present
    // process(5L); // Might be ambiguous or call process(double) depending on compiler rules/conversions

    return 0;
}
