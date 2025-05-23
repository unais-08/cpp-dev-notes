/**
 * @file switch_statement.cpp
 * @brief This file demonstrates the use of the switch statement for multi-way branching
 * based on the value of a single variable or expression.
 * It covers basic switch-case structure, the importance of 'break', and the 'default' case.
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
    int dayOfWeek = 3; // 1 = Monday, 2 = Tuesday, ..., 7 = Sunday
    char grade = 'B';
    int month = 1;

    std::cout << "--- 1. Basic switch Statement (Day of Week) ---" << std::endl;
    // A 'switch' statement evaluates an expression (dayOfWeek in this case)
    // and compares its value against a list of 'case' labels.
    // When a match is found, the code block associated with that 'case' is executed.
    switch (dayOfWeek)
    {
    case 1: // If dayOfWeek is 1
        std::cout << "It's Monday." << std::endl;
        break; // 'break' statement is CRUCIAL: it exits the switch statement.
               // Without 'break', execution "falls through" to the next case.
    case 2:    // If dayOfWeek is 2
        std::cout << "It's Tuesday." << std::endl;
        break;
    case 3: // If dayOfWeek is 3
        std::cout << "It's Wednesday." << std::endl;
        break;
    case 4: // If dayOfWeek is 4
        std::cout << "It's Thursday." << std::endl;
        break;
    case 5: // If dayOfWeek is 5
        std::cout << "It's Friday." << std::endl;
        break;
    case 6: // If dayOfWeek is 6
        std::cout << "It's Saturday." << std::endl;
        break;
    case 7: // If dayOfWeek is 7
        std::cout << "It's Sunday." << std::endl;
        break;
    default: // The 'default' case is optional and executes if no 'case' matches the expression.
        std::cout << "Invalid day of week entered." << std::endl;
        break; // It's good practice to also put a break here, though not strictly required
               // if it's the last statement in the switch.
    }

    std::cout << "\n--- 2. switch with Character (Grade System) ---" << std::endl;
    // The expression in a switch statement can also be a char.
    // Each 'case' label must be a constant integral expression (e.g., an integer or a character literal).
    switch (grade)
    {
    case 'A':
        std::cout << "Excellent!" << std::endl;
        break;
    case 'B':
        std::cout << "Good!" << std::endl;
        break;
    case 'C':
        std::cout << "Satisfactory." << std::endl;
        break;
    case 'D':
        std::cout << "Needs improvement." << std::endl;
        break;
    case 'F':
        std::cout << "Fail." << std::endl;
        break;
    default:
        std::cout << "Invalid grade entered." << std::endl;
        break;
    }

    std::cout << "\n--- 3. Demonstrating Fall-through (Omitting break) ---" << std::endl;
    // BE CAREFUL with fall-through! It can lead to unexpected behavior if not intentional.
    // In this example, if month is 1, it prints "Winter" AND "Spring" AND "Summer" AND "Autumn".
    std::cout << "Month " << month << " is: ";
    switch (month)
    {
    case 1:  // If month is 1, this case matches
    case 2:  // And because there's no break, execution continues to this case...
    case 12: // ...and this case. This is intentional for multiple cases sharing code.
        std::cout << "Winter. ";
        // No break here, so it falls through to the next case!
    case 3: // If month is 3, this case matches
    case 4:
    case 5:
        std::cout << "Spring. ";
        // No break here
    case 6: // If month is 6, this case matches
    case 7:
    case 8:
        std::cout << "Summer. ";
        // No break here
    case 9: // If month is 9, this case matches
    case 10:
    case 11:
        std::cout << "Autumn. ";
        break; // Finally, a break to exit the switch.
    default:
        std::cout << "Unknown month. ";
        break;
    }
    std::cout << std::endl;

    // Correct way to handle multiple cases with the same code block (intentional fall-through)
    std::cout << "\n--- 4. Corrected Fall-through (Multiple Cases) ---" << std::endl;
    // This is the common pattern for handling multiple cases that share the same logic.
    month = 2; // Let's test a month that should be Winter
    std::cout << "Month " << month << " is: ";
    switch (month)
    {
    case 1:
    case 2:
    case 12: // These cases all 'fall through' to the code block below them.
        std::cout << "Winter." << std::endl;
        break; // The 'break' here is essential to prevent falling into 'Spring'.
    case 3:
    case 4:
    case 5:
        std::cout << "Spring." << std::endl;
        break;
    case 6:
    case 7:
    case 8:
        std::cout << "Summer." << std::endl;
        break;
    case 9:
    case 10:
    case 11:
        std::cout << "Autumn." << std::endl;
        break;
    default:
        std::cout << "Invalid month." << std::endl;
        break;
    }

    // Return 0 to indicate successful program execution.
    return 0;
}