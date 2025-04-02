#include <iostream>
#include <limits>
using namespace std;

class Bank {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    Bank() : accountNumber(0), balance(0.0) {}
    
    void createAccount() {
        cout << "Enter your account number: ";
        while (!(cin >> accountNumber)) {
            cout << "Invalid input. Please enter a valid account number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(); // Clear buffer 
        cout << "Enter account holder name: ";
        getline(cin, holderName);

        cout << "Enter your initial balance: ";
        while (!(cin >> balance) || balance < 0) {
            cout << "Invalid input. Please enter a valid initial balance: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void deposit() {
        double depositAmount;
        cout << "Enter the amount you want to deposit: ";
        while (!(cin >> depositAmount) || depositAmount <= 0) {
            cout << "Invalid input. Enter a valid deposit amount: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        balance += depositAmount;
        cout << "Deposit successful. Your new balance is: " << balance << "\n";
    }

    void withdraw() {
        double withdrawAmount;
        cout << "Enter the amount you want to withdraw: ";
        while (!(cin >> withdrawAmount) || withdrawAmount <= 0) {
            cout << "Invalid input. Enter a valid withdrawal amount: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (withdrawAmount > balance) {
            cout << "Insufficient balance! Your current balance is: " << balance << "\n";
        } else {
            balance -= withdrawAmount;
            cout << "Withdrawal successful. New balance is: " << balance << "\n";
        }
    }

    void displayBalance() const {
        cout << "Your current balance is: " << balance << "\n";
    }

    void accountInfo() const {
        cout << "\nAccount Details:\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder: " << holderName << "\n";
        cout << "Account Balance: " << balance << "\n";
    }
};

class Saving : public Bank {
public:
    void calculateInterest() {
        double rateOfInterest;
        cout << "Enter the annual interest rate (%): ";
        while (!(cin >> rateOfInterest) || rateOfInterest <= 0) {
            cout << "Invalid input. Enter a valid interest rate: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        double earnedInterest = balance * (rateOfInterest / 100);
        balance += earnedInterest;
        cout << "Interest earned: $" << earnedInterest << "\nUpdated balance: " << balance << "\n";
    }
};

class FixedDeposit : public Bank {
public:
    void calculateDepositInterest() {
        const double fixedInterestRate = 0.02; // 2% per year
        double durationInYears;
        cout << "Enter the duration of the deposit in years: ";
        while (!(cin >> durationInYears) || durationInYears <= 0) {
            cout << "Invalid input. Enter a valid duration: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        double interest = balance * fixedInterestRate * durationInYears;
        balance += interest;
        cout << "Interest earned over " << durationInYears << " years: $" << interest << "\nUpdated balance: " << balance << "\n";
    }
};

int main() {
    int choice;
    Bank basicAccount;
    Saving savingsAccount;
    FixedDeposit fixedDepositAccount;
    
    do {
        cout << "\nSelect an option:\n";
        cout << "1. Create a basic account\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. View balance\n";
        cout << "5. Create a savings account and calculate interest\n";
        cout << "6. Create a fixed deposit account and calculate interest\n";
        cout << "7. Exit program\n";
        cout << "Enter your choice: ";
        
        while (!(cin >> choice) || choice < 1 || choice > 7) {
            cout << "Invalid input. Please enter a valid option (1-7): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            cout << "Creating a basic account...\n";
            basicAccount.createAccount();
            basicAccount.accountInfo();
            break;
        case 2:
            basicAccount.deposit();
            break;
        case 3:
            basicAccount.withdraw();
            break;
        case 4:
            basicAccount.displayBalance();
            break;
        case 5:
            cout << "Creating a savings account...\n";
            savingsAccount.createAccount();
            savingsAccount.calculateInterest();
            savingsAccount.accountInfo();
            break;
        case 6:
            cout << "Creating a fixed deposit account...\n";
            fixedDepositAccount.createAccount();
            fixedDepositAccount.calculateDepositInterest();
            fixedDepositAccount.accountInfo();
            break;
        case 7:
            cout << "Thank you! Exiting program.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 7);
    return 0;
}
