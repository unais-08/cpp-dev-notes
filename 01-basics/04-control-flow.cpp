/**
 * @file if_else.cpp
 * @brief This file demonstrates the use of if, else if, and else statements
 * for conditional execution in C++.
 * It covers single if statements, if-else pairs, and multiple else if ladders.
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
    int score = 75;
    int temperature = 28;
    int hour = 10;  // Using 24-hour format

    std::cout << "--- 1. Simple if Statement ---" << std::endl;
    // An 'if' statement executes a block of code if its condition is true.
    // The condition is an expression that evaluates to a boolean value (true or false).
    if (score >= 60)
    {  // Condition: Is score greater than or equal to 60?
        std::cout << "Congratulations! You passed the exam." << std::endl;
    }
    std::cout << "End of simple if statement example." << std::endl;

    // --- 2. if-else Statement ---
    // An 'if-else' statement provides two paths of execution:
    // one if the condition is true, and another if it's false.
    std::cout << "\n--- 2. if-else Statement ---" << std::endl;
    int number = 7;
    if (number % 2 == 0)
    {  // Condition: Is number divisible by 2 (even)?
        std::cout << number << " is an even number." << std::endl;
    }
    else
    {  // This block executes if the 'if' condition is false.
        std::cout << number << " is an odd number." << std::endl;
    }

    // Changing the number to test the 'if' part
    number = 4;
    if (number % 2 == 0)
    {
        std::cout << number << " is an even number." << std::endl;
    }
    else
    {
        std::cout << number << " is an odd number." << std::endl;
    }

    // --- 3. if-else if-else Ladder ---
    // Used when there are multiple conditions to check in sequence.
    // The first 'true' condition's block is executed, and the rest are skipped.
    // The 'else' block (if present) acts as a fallback if no other condition is true.
    std::cout << "\n--- 3. if-else if-else Ladder (Grading System) ---" << std::endl;

    if (score >= 90)
    {
        std::cout << "Your grade is A." << std::endl;
    }
    else if (score >= 80)
    {  // This is checked ONLY if the first 'if' was false.
        std::cout << "Your grade is B." << std::endl;
    }
    else if (score >= 70)
    {  // This is checked ONLY if the previous 'else if' was false.
        std::cout << "Your grade is C." << std::endl;
    }
    else if (score >= 60)
    {
        std::cout << "Your grade is D." << std::endl;
    }
    else
    {  // This is the default case if none of the above conditions are met.
        std::cout << "Your grade is F." << std::endl;
    }

    // Another example of if-else if-else (Time of Day)
    std::cout << "\n--- 4. if-else if-else (Time of Day) ---" << std::endl;

    if (hour >= 5 && hour < 12)
    {  // 5 AM to 11:59 AM
        std::cout << "Good Morning!" << std::endl;
    }
    else if (hour >= 12 && hour < 18)
    {  // 12 PM to 5:59 PM
        std::cout << "Good Afternoon!" << std::endl;
    }
    else if (hour >= 18 && hour < 22)
    {  // 6 PM to 9:59 PM
        std::cout << "Good Evening!" << std::endl;
    }
    else
    {  // 10 PM to 4:59 AM (or invalid hour)
        std::cout << "Good Night!" << std::endl;
    }

    // Example demonstrating block scope and single statements
    std::cout << "\n--- 5. Omitting Braces for Single Statements ---" << std::endl;
    int value = 5;
    if (value > 3)
        std::cout << "Value is greater than 3 (no braces)."
                  << std::endl;  // Single statement, no braces needed
    else
        std::cout << "Value is not greater than 3 (no braces)." << std::endl;

    // IMPORTANT: If you have multiple statements, you MUST use braces!
    // Example of potential error if braces are omitted:
    /*
    if (value > 3)
        std::cout << "Statement 1." << std::endl; // This is part of the if
        std::cout << "Statement 2." << std::endl; // This is ALWAYS executed, not part of the if!
    */

    // Return 0 to indicate successful program execution.
    return 0;
}