/* *********************************************************************************************************************************************** */
/*                                                                                                                                                 */
/* A console app in C++ for an ATM machine that asks for a pin, allows for withdawls, deposits and transfers and allows you to check your balance? */
/*                             By: Rick Herrera                                                    Date: 5/1/2023                                  */
/*                                                                                                                                                 */
/* *********************************************************************************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

// Function to validate a PIN entered by the user
bool validatePin(string correctPin)
{
    string enteredPin;
    cout << "Please enter your PIN: ";
    cin >> enteredPin;
    if (enteredPin == correctPin)
    {
        return true;
    }
    else
    {
        cout << "Invalid PIN. Please try again." << endl;
        return false;
    }
}

// Function to display the main menu options and return the user's selection
char displayMenuAndGetSelection()
{
    char selection;
    cout << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Check balance" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Transfer" << endl;
    cout << "5. Quit" << endl;
    cout << "Selection: ";
    cin >> selection;
    return selection;
}

// Function to display the balance
void displayBalance(double balance)
{
    cout << "Your current balance is: $" << balance << endl;
}

// Function to handle a withdrawal
void withdraw(double& balance)
{
    double amount;
    cout << "How much would you like to withdraw? $";
    cin >> amount;
    if (amount > balance)
    {
        cout << "Insufficient funds. Please try again." << endl;
    }
    else
    {
        balance -= amount;
        cout << "Transaction complete. Your new balance is: $" << balance << endl;
    }
}

// Function to handle a deposit
void deposit(double& balance)
{
    double amount;
    cout << "How much would you like to deposit? $";
    cin >> amount;
    balance += amount;
    cout << "Transaction complete. Your new balance is: $" << balance << endl;
}

// Function to handle a transfer
void transfer(double& balance1, double& balance2)
{
    double amount;
    cout << "How much would you like to transfer? $";
    cin >> amount;
    if (amount > balance1)
    {
        cout << "Insufficient funds. Please try again." << endl;
    }
    else
    {
        balance1 -= amount;
        balance2 += amount;
        cout << "Transaction complete. Your new balance is: $" << balance1 << endl;
    }
}

int main()
{
    string correctPin = "1234"; // Change this to the correct PIN for your account
    double balance = 1000.0; // Change this to your starting account balance
    double otherBalance = 2000.0; // Change this to the starting balance of the account you want to transfer to

    // Validate the PIN
    while (!validatePin(correctPin))
    {
        // Keep prompting the user for the PIN until it is correct
    }

    // Display the main menu and handle user input
    char selection;
    do
    {
        selection = displayMenuAndGetSelection();
        switch (selection)
        {
        case '1':
            displayBalance(balance);
            break;
        case '2':
            withdraw(balance);
            break;
        case '3':
            deposit(balance);
            break;
        case '4':
            transfer(balance, otherBalance);
            break;
        case '5':
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid selection. Please try again." << endl;
            break;
        }
    } while (selection != '5');
}