/**
 * @file while_do_while.cpp
 * @brief This file demonstrates the use of 'while' and 'do-while' loops in C++.
 * It covers the differences between the two, common use cases,
 * and how to control loop execution with 'break' and 'continue'.
 *
 * @author [Your Name/Alias]
 * @date 2025-05-23
 */

// Include necessary headers for input/output operations.
#include <iostream>

// The 'main' function is the entry point of the program.
// Program execution begins here.
int main()
{
    std::cout << "--- 1. while Loop (Entry-Controlled Loop) ---" << std::endl;
    // The 'while' loop checks the condition *before* each iteration.
    // If the condition is initially false, the loop body never executes.
    int count = 0;
    while (count < 5)
    {  // Condition: Loop as long as count is less than 5
        std::cout << "while loop count: " << count << std::endl;
        count++;  // Increment count to avoid an infinite loop
    }
    std::cout << "while loop finished." << std::endl;

    std::cout << "\n--- 2. do-while Loop (Exit-Controlled Loop) ---" << std::endl;
    // The 'do-while' loop checks the condition *after* each iteration.
    // This means the loop body *always* executes at least once, even if the condition is initially
    // false.
    int num = 10;
    do
    {
        std::cout << "do-while loop num: " << num << std::endl;
        num -= 2;  // Decrement num
    } while (num > 0);  // Condition: Loop as long as num is greater than 0
    std::cout << "do-while loop finished." << std::endl;

    std::cout << "\n--- 3. Using 'break' to Exit a Loop ---" << std::endl;
    // The 'break' statement immediately terminates the innermost enclosing loop
    // (either 'while', 'do-while', or 'for').
    int i = 0;
    while (true)
    {  // Infinite loop (we'll break out of it)
        std::cout << "i: " << i << std::endl;
        if (i == 3)
        {
            std::cout << "Breaking out of the loop when i is 3." << std::endl;
            break;  // Exit the loop
        }
        i++;
    }

    std::cout << "\n--- 4. Using 'continue' to Skip an Iteration ---" << std::endl;
    // The 'continue' statement skips the rest of the current iteration
    // and jumps to the next iteration of the loop.
    for (int j = 0; j < 5; j++)
    {
        if (j == 2)
        {
            std::cout << "Skipping iteration 2 (continue)." << std::endl;
            continue;  // Skip the rest of this iteration
        }
        std::cout << "j: " << j << std::endl;
    }

    std::cout << "\n--- 5. Example: Input Validation with do-while ---" << std::endl;
    // do-while loops are often useful for input validation because you want to
    // prompt the user *at least once*.
    int age;
    do
    {
        std::cout << "Enter your age (must be between 0 and 120): ";
        std::cin >> age;  // Read input from the user
        if (age < 0 || age > 120)
        {
            std::cout << "Invalid age. Please try again." << std::endl;
        }
    } while (age < 0 || age > 120);  // Loop continues as long as the age is invalid
    std::cout << "Valid age entered: " << age << std::endl;

    // Return 0 to indicate successful program execution.
    return 0;
}