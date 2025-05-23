#include <iostream>
#include <limits>
#include <memory>

class Bank_Account
{
public:
    static constexpr const char *bank_name = "State Bank of C++";

private:
    const int account_no;
    double current_balance;

public:
    Bank_Account(int account_no, double initial_balance)
        : account_no(account_no), current_balance(initial_balance > 0 ? initial_balance : 0.0) {}

    int get_account_no() const { return account_no; }

    void print_balance() const
    {
        std::cout << "Balance: $" << current_balance << '\n';
    }

    bool withdraw(double amount)
    {
        if (amount <= 0)
        {
            std::cout << "Withdrawal amount must be positive.\n";
            return false;
        }
        if (amount > current_balance)
        {
            std::cout << "Insufficient funds.\n";
            return false;
        }
        current_balance -= amount;
        std::cout << "Successfully withdrew: $" << amount << '\n';
        print_balance();
        return true;
    }

    bool deposit(double amount)
    {
        if (amount <= 0)
        {
            std::cout << "Deposit amount must be positive.\n";
            return false;
        }
        current_balance += amount;
        std::cout << "Successfully deposited: $" << amount << '\n';
        print_balance();
        return true;
    }

    bool send_money(Bank_Account &recipient, double amount)
    {
        if (this == &recipient)
        {
            std::cout << "Cannot send money to the same account.\n";
            return false;
        }
        if (withdraw(amount))
        {
            recipient.deposit(amount);
            std::cout << "Sent $" << amount << " to account #" << recipient.get_account_no() << '\n';
            return true;
        }
        return false;
    }
};

void clear_input()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double get_positive_amount(const std::string &prompt)
{
    double amount;
    while (true)
    {
        std::cout << prompt;
        std::cin >> amount;
        if (std::cin.fail() || amount <= 0)
        {
            std::cout << "Invalid amount. Please enter a positive number.\n";
            clear_input();
        }
        else
        {
            clear_input();
            return amount;
        }
    }
}

int main()
{
    std::string username = "Shaikh";
    auto user_account = std::make_unique<Bank_Account>(759654, 100.0);
    auto friend_account = std::make_unique<Bank_Account>(123456, 50.0); // Example recipient

    std::cout << "Welcome to " << Bank_Account::bank_name << " ATM, " << username << '\n';

    while (true)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1: Check balance\n";
        std::cout << "2: Withdraw money\n";
        std::cout << "3: Deposit money\n";
        std::cout << "4: Send money\n";
        std::cout << "5: Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        clear_input();

        switch (choice)
        {
        case 1:
            user_account->print_balance();
            break;
        case 2:
        {
            double amount = get_positive_amount("Enter amount to withdraw: ");
            user_account->withdraw(amount);
            break;
        }
        case 3:
        {
            double amount = get_positive_amount("Enter amount to deposit: ");
            user_account->deposit(amount);
            break;
        }
        case 4:
        {
            std::cout << "Sending to friend account #" << friend_account->get_account_no() << '\n';
            double amount = get_positive_amount("Enter amount to send: ");
            user_account->send_money(*friend_account, amount);
            break;
        }
        case 5:
            std::cout << "Thank you for using our ATM. Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
