/**
 * @file hello_world.cpp
 * @brief This file contains the classic "Hello, World!" program.
 * It demonstrates the fundamental structure of a C++ program,
 * including basic input/output operations using iostream.
 *
 * @author Shaikh Unais
 * @date 2025-05-23e
 */

// Include necessary headers for input/output operations.
// iostream is the standard library for stream-based input and output.
#include <iostream>

// The 'main' function is the entry point of every C++ program.
// Execution of the program begins here.
// 'int' indicates that the main function will return an integer value to the operating system.
// A return value of 0 typically signifies successful execution.
int main()
{
    // std::cout is the standard output stream object.
    // It is used to print data to the console (standard output).
    // The '<<' operator is the insertion operator, used to insert data into the stream.
    // "Hello, World!" is a string literal that will be printed.
    // std::endl is a manipulator that inserts a newline character and flushes the output buffer.
    // This ensures that the output is immediately visible on the console.
    std::cout << "Hello, World!" << std::endl;

    // Return 0 to indicate that the program executed successfully.
    // This is a common convention and good practice.
    return 0;
}