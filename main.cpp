#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ---------------- Bank Class ----------------
class BankAccount {

private:
    int accountNumber;
    string name;
    float balance;

public:

    // Create Account
    void createAccount() {

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        // Save data to file
        ofstream file("bank.txt", ios::app);

        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;

        file.close();

        cout << "Account Created Successfully!\n";
    }

    // Deposit Money
    void deposit() {

        int accNo;
        float amount;
        bool found = false;

        cout << "Enter Account Number: ";
        cin >> accNo;

        cout << "Enter Deposit Amount: ";
        cin >> amount;

        ifstream infile("bank.txt");
        ofstream outfile("temp.txt");

        int acc;
        string customerName;
        float bal;

        while (infile >> acc) {

            infile.ignore();
            getline(infile, customerName);
            infile >> bal;

            if (acc == accNo) {

                bal += amount;

                cout << "Amount Deposited Successfully!\n";
                found = true;
            }

            outfile << acc << endl;
            outfile << customerName << endl;
            outfile << bal << endl;
        }

        infile.close();
        outfile.close();

        remove("bank.txt");
        rename("temp.txt", "bank.txt");

        if (!found)
            cout << "Account Not Found!\n";
    }

    // Withdraw Money
    void withdraw() {

        int accNo;
        float amount;
        bool found = false;

        cout << "Enter Account Number: ";
        cin >> accNo;

        cout << "Enter Withdrawal Amount: ";
        cin >> amount;

        ifstream infile("bank.txt");
        ofstream outfile("temp.txt");

        int acc;
        string customerName;
        float bal;

        while (infile >> acc) {

            infile.ignore();
            getline(infile, customerName);
            infile >> bal;

            if (acc == accNo) {

                if (amount <= bal) {

                    bal -= amount;

                    cout << "Withdrawal Successful!\n";
                }
                else {

                    cout << "Insufficient Balance!\n";
                }

                found = true;
            }

            outfile << acc << endl;
            outfile << customerName << endl;
            outfile << bal << endl;
        }

        infile.close();
        outfile.close();

        remove("bank.txt");
        rename("temp.txt", "bank.txt");

        if (!found)
            cout << "Account Not Found!\n";
    }

    // Balance Check
    void checkBalance() {

        int accNo;
        bool found = false;

        cout << "Enter Account Number: ";
        cin >> accNo;

        ifstream file("bank.txt");

        int acc;
        string customerName;
        float bal;

        while (file >> acc) {

            file.ignore();
            getline(file, customerName);
            file >> bal;

            if (acc == accNo) {

                cout << "\n----- Account Details -----\n";

                cout << "Account Number : " << acc << endl;
                cout << "Customer Name  : " << customerName << endl;
                cout << "Balance        : " << bal << endl;

                found = true;
                break;
            }
        }

        file.close();

        if (!found)
            cout << "Account Not Found!\n";
    }
};

// ---------------- Main Function ----------------
int main() {

    BankAccount bank;

    int choice;

    do {

        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";

        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bank.createAccount();
            break;

        case 2:
            bank.deposit();
            break;

        case 3:
            bank.withdraw();
            break;

        case 4:
            bank.checkBalance();
            break;

        case 5:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
