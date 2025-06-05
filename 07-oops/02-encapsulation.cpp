/**

 * This file provides comprehensive documentation and examples for the
 * concept of Encapsulation in C++ Object-Oriented Programming (OOP).
 *
 * Encapsulation is one of the fundamental principles of OOP. It refers to
 * the bundling of data (attributes) and the methods (functions) that operate
 * on the data within a single unit or class. It also involves restricting
 * direct access to some of an object's components, which is achieved through
 * access specifiers like 'private', 'protected', and 'public'.
 *
 * Key aspects of Encapsulation:
 * 1.  Data Hiding: Protecting the internal state of an object from direct
 * external access. This is typically done by declaring member variables
 * as 'private'.
 * 2.  Bundling: Grouping data and methods that operate on that data into
 * a single class.
 * 3.  Controlled Access: Providing public methods (often called "getters"
 * and "setters") to allow indirect and controlled access to the private
 * data. This allows for validation and ensures data integrity.
 *
 * Benefits of Encapsulation:
 * -   Data Integrity: Prevents unauthorized or invalid data modifications.
 * -   Flexibility: Allows internal implementation details to change without
 * affecting external code that uses the class.
 * -   Maintainability: Makes code easier to maintain and debug by localizing
 * changes within the class.
 * -   Security: Protects sensitive data from direct manipulation.
 *
 * Author: Gemini
 * Date: May 31, 2025
 */

#include <iostream>  // Required for input/output operations (e.g., std::cout)
#include <string>    // Required for std::string
#include <limits>    // Required for std::numeric_limits
#include <ios>       // Required for std::streamsize

/**
 * @class BankAccount
 * @brief Demonstrates the concept of encapsulation.
 *
 * This class encapsulates the data related to a bank account (account number,
 * account holder name, and balance) and provides public methods to interact
 * with this data in a controlled manner.
 */
class BankAccount
{
   private:
    // Private member variables (attributes)
    // These are hidden from direct external access, enforcing data hiding.
    std::string accountNumber;
    std::string accountHolderName;
    double accountBalance;  // Stored in cents or as a double for simplicity in example

   public:
    /**
     * @brief Constructor for the BankAccount class.
     *
     * Initializes a new BankAccount object with provided details.
     *
     * @param accNum The account number.
     * @param holderName The name of the account holder.
     * @param initialBalance The initial balance for the account.
     */
    BankAccount(const std::string& accNum, const std::string& holderName, double initialBalance)
    {
        accountNumber = accNum;
        accountHolderName = holderName;
        // Validate initial balance to ensure data integrity
        if (initialBalance >= 0)
        {
            accountBalance = initialBalance;
        }
        else
        {
            std::cout << "Warning: Initial balance cannot be negative. Setting to 0.0."
                      << std::endl;
            accountBalance = 0.0;
        }
    }

    /**
     * @brief Getter method for the account number.
     * @return The account number as a string.
     */
    std::string getAccountNumber() const { return accountNumber; }

    /**
     * @brief Getter method for the account holder's name.
     * @return The account holder's name as a string.
     */
    std::string getAccountHolderName() const { return accountHolderName; }

    /**
     * @brief Setter method for the account holder's name.
     *
     * Allows updating the account holder's name. Includes basic validation.
     *
     * @param newName The new name for the account holder.
     */
    void setAccountHolderName(const std::string& newName)
    {
        if (!newName.empty())
        {  // Simple validation: name should not be empty
            accountHolderName = newName;
            std::cout << "Account holder name updated to: " << newName << std::endl;
        }
        else
        {
            std::cout << "Error: Account holder name cannot be empty." << std::endl;
        }
    }

    /**
     * @brief Getter method for the account balance.
     * @return The current account balance as a double.
     */
    double getAccountBalance() const { return accountBalance; }

    /**
     * @brief Deposits an amount into the account.
     *
     * This method provides a controlled way to increase the account balance.
     * It includes validation to ensure only positive amounts can be deposited.
     *
     * @param amount The amount to deposit.
     * @return True if the deposit was successful, false otherwise.
     */
    bool deposit(double amount)
    {
        if (amount > 0)
        {
            accountBalance += amount;
            std::cout << "Deposited: $" << amount << ". New balance: $" << accountBalance
                      << std::endl;
            return true;
        }
        else
        {
            std::cout << "Error: Deposit amount must be positive." << std::endl;
            return false;
        }
    }

    /**
     * @brief Withdraws an amount from the account.
     *
     * This method provides a controlled way to decrease the account balance.
     * It includes validation to ensure sufficient funds and positive withdrawal amount.
     *
     * @param amount The amount to withdraw.
     * @return True if the withdrawal was successful, false otherwise.
     */
    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            std::cout << "Error: Withdrawal amount must be positive." << std::endl;
            return false;
        }
        if (accountBalance >= amount)
        {
            accountBalance -= amount;
            std::cout << "Withdrew: $" << amount << ". New balance: $" << accountBalance
                      << std::endl;
            return true;
        }
        else
        {
            std::cout << "Error: Insufficient funds. Current balance: $" << accountBalance
                      << std::endl;
            return false;
        }
    }

    /**
     * @brief Displays the account details.
     *
     * This method provides a public interface to view the account's state.
     */
    void displayAccountInfo() const
    {
        std::cout << "\n--- Account Information ---" << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Balance: $" << accountBalance << std::endl;
        std::cout << "---------------------------\n" << std::endl;
    }
};

/**
 * @brief Main function to demonstrate BankAccount encapsulation.
 *
 * This function creates BankAccount objects and interacts with them using
 * their public interfaces, illustrating how encapsulation protects internal
 * data and maintains integrity.
 */
int main()
{
    std::cout << "--- Demonstrating Encapsulation with BankAccount ---\n" << std::endl;

    // 1. Create a BankAccount object
    // The constructor ensures initial data is valid.
    BankAccount myAccount("1234567890", "Alice Smith", 1000.00);
    myAccount.displayAccountInfo();

    // 2. Attempt to access private members directly (will cause a compile-time error)
    // Uncommenting the line below would result in:
    // error: 'accountBalance' is private within this context
    // myAccount.accountBalance = -500;

    // 3. Interact with the account using public methods (controlled access)
    // Deposit funds
    myAccount.deposit(200.50);
    myAccount.deposit(-50.00);  // Attempting invalid deposit

    // Withdraw funds
    myAccount.withdraw(150.00);
    myAccount.withdraw(2000.00);  // Attempting withdrawal with insufficient funds
    myAccount.withdraw(0.00);     // Attempting invalid withdrawal

    myAccount.displayAccountInfo();

    // 4. Update account holder name using a setter
    myAccount.setAccountHolderName("Alice Johnson");
    myAccount.setAccountHolderName("");  // Attempting invalid name change

    myAccount.displayAccountInfo();

    // 5. Create another account with an invalid initial balance
    BankAccount savingsAccount("9876543210", "Bob Brown", -50.00);  // Invalid initial balance
    savingsAccount.displayAccountInfo();

    std::cout << "--- Encapsulation Demonstration Complete ---" << std::endl;

    // Keep console open in some environments
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // std::cout << "Press Enter to exit...";
    // std::cin.get();

    return 0;  // Indicate successful execution
}
