/**
 * @file operators.cpp
 * @brief This file demonstrates the different types of operators in C++,
 * including arithmetic, relational, logical, assignment, increment/decrement,
 * and a few other miscellaneous operators.
 * It shows how to use them with variables and values.
 *
 * @author SU
 * @date 2025-05-23
 */

// Include necessary headers for input/output operations.
#include <iostream>

// The 'main' function is the entry point of the program.
// Program execution begins here.
int main()
{
    // Declare some variables to use with operators
    int a = 10;
    int b = 3;
    int result;
    bool booleanResult;

    std::cout << "Initial values: a = " << a << ", b = " << b << std::endl;

    // --- 1. Arithmetic Operators ---
    // Used for mathematical calculations.
    std::cout << "\n--- 1. Arithmetic Operators ---" << std::endl;

    // Addition operator (+)
    result = a + b;
    std::cout << "a + b = " << result << std::endl; // Expected: 13

    // Subtraction operator (-)
    result = a - b;
    std::cout << "a - b = " << result << std::endl; // Expected: 7

    // Multiplication operator (*)
    result = a * b;
    std::cout << "a * b = " << result << std::endl; // Expected: 30

    // Division operator (/)
    // For integers, division performs integer division (truncates decimal part).
    result = a / b;
    std::cout << "a / b (integer division) = " << result << std::endl; // Expected: 3 (10 / 3 = 3.33...)

    // To get floating-point division, at least one operand must be a float/double.
    double floatA = 10.0;
    double floatB = 3.0;
    double floatResult = floatA / floatB;
    std::cout << "floatA / floatB (floating-point division) = " << floatResult << std::endl; // Expected: 3.333...

    // Modulus operator (%)
    // Returns the remainder of an integer division.
    result = a % b;
    std::cout << "a % b (remainder) = " << result << std::endl; // Expected: 1 (10 / 3 = 3 with remainder 1)

    // --- 2. Relational (Comparison) Operators ---
    // Used to compare two operands and return a boolean result (true or false).
    std::cout << "\n--- 2. Relational Operators ---" << std::endl;
    std::cout << std::boolalpha; // To print 'true'/'false' instead of 1/0

    // Equal to (==)
    booleanResult = (a == b);
    std::cout << "a == b: " << booleanResult << std::endl; // Expected: false (10 is not equal to 3)

    // Not equal to (!=)
    booleanResult = (a != b);
    std::cout << "a != b: " << booleanResult << std::endl; // Expected: true (10 is not equal to 3)

    // Greater than (>)
    booleanResult = (a > b);
    std::cout << "a > b: " << booleanResult << std::endl; // Expected: true (10 is greater than 3)

    // Less than (<)
    booleanResult = (a < b);
    std::cout << "a < b: " << booleanResult << std::endl; // Expected: false (10 is not less than 3)

    // Greater than or equal to (>=)
    booleanResult = (a >= b);
    std::cout << "a >= b: " << booleanResult << std::endl; // Expected: true (10 is greater than or equal to 3)

    // Less than or equal to (<=)
    booleanResult = (a <= b);
    std::cout << "a <= b: " << booleanResult << std::endl; // Expected: false (10 is not less than or equal to 3)

    std::cout << std::noboolalpha; // Reset boolalpha

    // --- 3. Logical Operators ---
    // Used to combine or negate boolean expressions.
    std::cout << "\n--- 3. Logical Operators ---" << std::endl;
    bool x = true;
    bool y = false;
    std::cout << "Boolean values: x = " << std::boolalpha << x << ", y = " << y << std::endl;
    std::cout << std::noboolalpha;

    // Logical AND (&&)
    // Returns true if both operands are true.
    booleanResult = (x && y);
    std::cout << "x && y: " << std::boolalpha << booleanResult << std::endl; // Expected: false

    // Logical OR (||)
    // Returns true if at least one operand is true.
    booleanResult = (x || y);
    std::cout << "x || y: " << std::boolalpha << booleanResult << std::endl; // Expected: true

    // Logical NOT (!)
    // Reverses the logical state of its operand.
    booleanResult = (!x);
    std::cout << "!x: " << std::boolalpha << booleanResult << std::endl; // Expected: false
    std::cout << std::noboolalpha;

    // --- 4. Assignment Operators ---
    // Used to assign values to variables.
    std::cout << "\n--- 4. Assignment Operators ---" << std::endl;
    int c = 5;
    std::cout << "Initial value: c = " << c << std::endl;

    // Simple assignment (=)
    c = 20;                                        // Assigns 20 to c
    std::cout << "c = 20; c = " << c << std::endl; // Expected: 20

    // Compound assignment operators (shorthand for operation + assignment)
    // += (add and assign)
    c += 5;                                        // Equivalent to: c = c + 5;
    std::cout << "c += 5; c = " << c << std::endl; // Expected: 25

    // -= (subtract and assign)
    c -= 10;                                        // Equivalent to: c = c - 10;
    std::cout << "c -= 10; c = " << c << std::endl; // Expected: 15

    // *= (multiply and assign)
    c *= 2;                                        // Equivalent to: c = c * 2;
    std::cout << "c *= 2; c = " << c << std::endl; // Expected: 30

    // /= (divide and assign)
    c /= 3;                                        // Equivalent to: c = c / 3;
    std::cout << "c /= 3; c = " << c << std::endl; // Expected: 10

    // %= (modulus and assign)
    c %= 3;                                        // Equivalent to: c = c % 3;
    std::cout << "c %= 3; c = " << c << std::endl; // Expected: 1

    // --- 5. Increment (++) and Decrement (--) Operators ---
    // Used to increase or decrease a variable's value by 1.
    std::cout << "\n--- 5. Increment/Decrement Operators ---" << std::endl;
    int count = 5;
    std::cout << "Initial count = " << count << std::endl;

    // Post-increment (count++)
    // Uses the current value of count, then increments count.
    result = count++;
    std::cout << "result = count++; result = " << result << ", count = " << count << std::endl; // result=5, count=6

    // Pre-increment (++count)
    // Increments count, then uses the new value of count.
    result = ++count;
    std::cout << "result = ++count; result = " << result << ", count = " << count << std::endl; // result=7, count=7

    // Post-decrement (count--)
    result = count--;
    std::cout << "result = count--; result = " << result << ", count = " << count << std::endl; // result=7, count=6

    // Pre-decrement (--count)
    result = --count;
    std::cout << "result = --count; result = " << result << ", count = " << count << std::endl; // result=5, count=5

    // --- 6. Ternary (Conditional) Operator ---
    // A shorthand for an if-else statement.
    // Syntax: condition ? expression_if_true : expression_if_false;
    std::cout << "\n--- 6. Ternary (Conditional) Operator ---" << std::endl;
    int num1 = 15;
    int num2 = 10;
    int max = (num1 > num2) ? num1 : num2;
    std::cout << "Max of " << num1 << " and " << num2 << " is: " << max << std::endl; // Expected: 15

    // --- 7. sizeof Operator ---
    // Returns the size in bytes of a variable or a data type.
    std::cout << "\n--- 7. sizeof Operator ---" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of variable 'a': " << sizeof(a) << " bytes" << std::endl; // 'a' is an int

    // Return 0 to indicate successful program execution.
    return 0;
}