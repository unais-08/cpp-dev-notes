/**
 * @file for_loop.cpp
 * @brief This file demonstrates the use of the 'for' loop in C++.
 * It covers basic for loop syntax, variations including infinite loops,
 * and iterating over various ranges.
 *
 * @author [Your Name/Alias]
 * @date 2025-05-23
 */

// Include necessary headers for input/output operations.
#include <iostream>
#include <vector>  // Required for std::vector, used in range-based for loop example

// The 'main' function is the entry point of the program.
// Program execution begins here.
int main()
{
    std::cout << "--- 1. Basic for Loop (Counting Up) ---" << std::endl;
    // The 'for' loop has three parts, separated by semicolons:
    // 1. Initialization: Executed once at the beginning of the loop.
    //    (e.g., int i = 0;) - declares and initializes the loop counter.
    // 2. Condition: Evaluated before each iteration. If true, the loop body executes.
    //    If false, the loop terminates.
    //    (e.g., i < 5;) - loop continues as long as i is less than 5.
    // 3. Increment/Decrement: Executed after each iteration of the loop body.
    //    (e.g., i++) - increments the loop counter.
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Loop iteration (i): " << i << std::endl;
    }
    std::cout << "Loop finished. (i is now out of scope or last value: 5 if declared outside)"
              << std::endl;
    // Note: 'i' is typically scoped to the loop itself (C++11 onwards).

    std::cout << "\n--- 2. for Loop (Counting Down) ---" << std::endl;
    // The loop can also count downwards.
    for (int j = 10; j > 0; j -= 2)
    {  // Start at 10, loop while > 0, decrement by 2
        std::cout << "Countdown (j): " << j << std::endl;
    }

    std::cout << "\n--- 3. for Loop with Floating-Point Counter ---" << std::endl;
    // While possible, using floating-point numbers for loop counters
    // can sometimes lead to precision issues. Generally, use integers.
    for (double k = 0.0; k <= 1.0; k += 0.2)
    {
        std::cout << "Float counter (k): " << k << std::endl;
    }

    std::cout << "\n--- 4. Summation with a for Loop ---" << std::endl;
    int sum = 0;
    for (int num = 1; num <= 10; num++)
    {
        sum += num;  // Add current 'num' to 'sum'
    }
    std::cout << "Sum of numbers from 1 to 10: " << sum << std::endl;  // Expected: 55

    std::cout << "\n--- 5. Nested for Loops (Multiplication Table) ---" << std::endl;
    // Loops can be nested inside each other.
    // The inner loop completes all its iterations for each single iteration of the outer loop.
    std::cout << "Simple Multiplication Table (1-3):" << std::endl;
    for (int i = 1; i <= 3; i++)
    {  // Outer loop (rows)
        for (int j = 1; j <= 3; j++)
        {                                                              // Inner loop (columns)
            std::cout << i << " * " << j << " = " << (i * j) << "\t";  // '\t' for tab spacing
        }
        std::cout << std::endl;  // New line after each row
    }

    std::cout << "\n--- 6. Range-based for Loop (C++11 and later) ---" << std::endl;
    // This is a convenient way to iterate over elements of a range (like arrays, vectors).
    // Syntax: for (declaration : range) { loop_body }
    std::vector<int> numbers = {10, 20, 30, 40, 50};  // std::vector is a dynamic array
    std::cout << "Iterating over a vector using range-based for loop:" << std::endl;
    for (int n : numbers)
    {  // 'n' will take on the value of each element in 'numbers'
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating over a C-style array:" << std::endl;
    int scores[] = {85, 92, 78, 95};  // C-style array
    // Note: You cannot directly use range-based for loop on a pointer to an array
    // if the size is not known at compile time. Here, 'scores' is an array, so it works.
    for (int s : scores)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::cout << "\n--- 7. Omitting Loop Parts (Use with caution!) ---" << std::endl;
    // While possible, it's generally discouraged for clarity.
    // You can omit any or all of the three parts, but you must keep the semicolons.
    // If the condition is omitted, it defaults to 'true', creating an infinite loop.

    // Example 1: Initialization outside, condition and increment inside
    int count = 0;
    for (; count < 3;)
    {  // No init, no increment
        std::cout << "Count: " << count << std::endl;
        count++;  // Increment inside the loop body
    }

    // Example 2: "Infinite" loop (will keep running until explicitly stopped, e.g., Ctrl+C)
    // Uncomment the following block ONLY if you understand it and know how to stop it!
    /*
    std::cout << "\n--- WARNING: Infinite Loop ahead! Uncomment to see. ---" << std::endl;
    for (;;) { // All three parts are omitted. Condition defaults to true.
        std::cout << "This loop runs forever! (Press Ctrl+C to stop)" << std::endl;
        // In real applications, such loops have internal break conditions or are daemon processes.
        // For demonstration, we'll comment it out to prevent endless output.
        // If you run it, you'll need to manually stop your terminal/program.
        // break; // If you add a break, it will only run once.
    }
    */

    // Return 0 to indicate successful program execution.
    return 0;
}