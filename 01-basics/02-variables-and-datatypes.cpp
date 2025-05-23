/**
 * @file variables.cpp
 * @brief This file demonstrates the declaration, initialization, and usage
 * of various fundamental (built-in) data types in C++.
 * It covers integer types, floating-point types, character types,
 * and boolean types, along with basic output.
 *
 * @author SU
 * @date 2025-05-23
 */

// Include necessary headers for input/output operations.
// iostream is essential for using std::cout to display values.
#include <iostream>

// The 'main' function is the entry point of the program.
// Program execution begins here.
int main()
{
    // --- 1. Integer Data Types ---
    // Integer types are used to store whole numbers (positive, negative, or zero).

    // 'int': The most common integer type. Its size is typically 4 bytes (32 bits),
    // but it can vary based on the system.
    // It can store values roughly from -2 billion to +2 billion.
    int age = 30; // Declaration and initialization of an integer variable.
    std::cout << "1. Integer Types:" << std::endl;
    std::cout << "Age: " << age << std::endl;

    // 'short int' (or just 'short'): Typically 2 bytes (16 bits).
    // Used for smaller integer values, conserving memory.
    short int smallNumber = 100;
    std::cout << "Small Number (short): " << smallNumber << std::endl;

    // 'long int' (or just 'long'): Typically 4 or 8 bytes (32 or 64 bits).
    // Guarantees at least the range of 'int'.
    long int distance = 1000000000; // 1 billion
    std::cout << "Distance (long): " << distance << std::endl;

    // 'long long int' (or just 'long long'): Guarantees at least 8 bytes (64 bits).
    // Used for very large integer values.
    long long int population = 8000000000LL; // 8 billion (LL suffix for long long literal)
    std::cout << "Population (long long): " << population << std::endl;

    // Unsigned integer types: Store only non-negative values (0 and positive).
    // They double the positive range by not needing to store negative values.
    unsigned int positiveCount = 1500;
    std::cout << "Positive Count (unsigned int): " << positiveCount << std::endl;

    // --- 2. Floating-Point Data Types ---
    // Floating-point types are used to store numbers with decimal points.

    // 'float': Single-precision floating-point type. Typically 4 bytes.
    // Provides about 6-7 decimal digits of precision.
    float temperature = 25.5f; // 'f' suffix is important for float literals
    std::cout << "\n2. Floating-Point Types:" << std::endl;
    std::cout << "Temperature (float): " << temperature << std::endl;

    // 'double': Double-precision floating-point type. Typically 8 bytes.
    // Provides about 15-17 decimal digits of precision. This is the default
    // floating-point literal type.
    double pi = 3.1415926535;
    std::cout << "Pi (double): " << pi << std::endl;

    // 'long double': Extended precision floating-point type. Size varies (e.g., 10 or 16 bytes).
    // Provides even more precision, if available.
    long double precisePi = 3.14159265358979323846L; // 'L' suffix for long double literal
    std::cout << "Precise Pi (long double): " << precisePi << std::endl;

    // --- 3. Character Data Type ---
    // 'char': Used to store single characters (letters, numbers, symbols).
    // Internally, characters are stored as small integer values (ASCII/Unicode).
    char grade = 'A'; // Single quotes for character literals
    char initial = 'J';
    std::cout << "\n3. Character Type:" << std::endl;
    std::cout << "Grade: " << grade << std::endl;
    std::cout << "Initial: " << initial << std::endl;

    // --- 4. Boolean Data Type ---
    // 'bool': Used to store logical values: 'true' or 'false'.
    // Typically takes 1 byte of memory.
    bool isOpen = true;     // Represents a true condition
    bool hasErrors = false; // Represents a false condition
    std::cout << "\n4. Boolean Type:" << std::endl;
    std::cout << "Is Open: " << isOpen << std::endl; // Prints 1 for true, 0 for false by default
    std::cout << "Has Errors: " << hasErrors << std::endl;

    // It's good practice to make the output clearer for booleans:
    // std::boolalpha manipulator makes cout print "true" or "false" instead of 1 or 0.
    std::cout << std::boolalpha; // Sets output stream to print bools as "true"/"false"
    std::cout << "Is Open (boolalpha): " << isOpen << std::endl;
    std::cout << "Has Errors (boolalpha): " << hasErrors << std::endl;
    std::cout << std::noboolalpha; // Resets output stream to print bools as 1/0

    // --- 5. Variable Declaration vs. Initialization ---
    // Declaration: Reserves memory for a variable, but doesn't give it a value.
    int declaredVariable; // declaredVariable now holds an "indeterminate" value (garbage)

    // Initialization: Assigns an initial value to a variable at the time of declaration.
    int initializedVariable = 10;

    // Assignment: Changing the value of an already declared variable.
    declaredVariable = 20; // Now declaredVariable has a defined value

    std::cout << "\n5. Declaration vs. Initialization:" << std::endl;
    std::cout << "Initialized Variable: " << initializedVariable << std::endl;
    std::cout << "Declared and then Assigned Variable: " << declaredVariable << std::endl;

    // Best practice: Always initialize your variables to avoid unexpected behavior.
    // Uninitialized variables can lead to subtle bugs.

    // Return 0 to indicate successful program execution.
    return 0;
}