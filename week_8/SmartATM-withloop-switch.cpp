#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>

using namespace std;

//Requirements
// ATM RULES
// • The correct ATM PIN is 2026.
// • A minimum balance of N5,000 must remain in the account after a successful transaction.
// • The maximum withdrawal allowed in a single transaction is N100,000.
// • The bank charges 1% of the withdrawal amount.
// • For every successful transaction, the program should generate a random 4-digit transaction ID.
// • A withdrawal of N50,000 or more should display a large-withdrawal notice.


//Constants
constexpr unsigned int accessPIN = 2026; //Correct ATM pin
constexpr double minimumBalance = 5000.0;
constexpr double maximumWithdrawal = 100000.0;
constexpr double bankCharge = 0.01; //percentage
constexpr int largeWithdrawal = 50000;


/// @brief Creates a Customer object from the entered account details
/// @param customerName the customer's name
/// @param accountNumber the customer's account number
/// @param currentBalance the customer's current balance
/// @param accessPIN the customer's PIN
/// @return a populated Customer object
struct Customer{
    string customerName;
    string accountNumber;
    double currentBalance;
    unsigned int accessPIN;
};


/// @brief Calculates the bank charges based on the withdrawal amount
/// @param withdrawalAmount the amount the customer wants to withdraw
/// @return the bank charge, calculated as 1% of the withdrawal amount
double bankChargeAmount(double withdrawalAmount){
    return (withdrawalAmount * bankCharge);
}


/// @brief Returns the final debit amount from adding the withdrawal amount and bank charge
/// @param withdrawalAmount the amount the customer wants to withdraw
/// @param bankCharge the calculated bank charge for this transaction
/// @return the total amount to be debited from the account
double totalDebitAmount(double withdrawalAmount, double bankCharge){
    return (withdrawalAmount + bankCharge);
}


/// @brief Calculates the customer's new balance after a withdrawal
/// @param currentBalance the customer's balance before this transaction
/// @param totalDebitAmount the total amount being debited (withdrawal + bank charge)
/// @return the customer's balance after the debit is applied
double newBalance(double currentBalance, double totalDebitAmount){
    return (currentBalance - totalDebitAmount);
}


/// @brief Generates a random 4-digit transaction ID.
/// @return a random 4-digit integer
inline unsigned int generateTransactionID(){

    return (rand() % 9000) + 1000; //fix //TODO
    //rand() % (max-min+1)
}

//customer struct
Customer createCustomer(
    string customerName,
    string accountNumber,
    double currentBalance,
    unsigned int accessPIN
)
{
    Customer customer = {customerName, accountNumber, currentBalance, accessPIN};

    return customer;
}


/// @brief Handles all input/ouput
void handleDisplay(){


    string customerName;
    string accountNumber;
    double currentBalance;
    unsigned int PIN;
    double withdrawalAmount;

    cout << "======================\n";
    cout << "SMART ATM\t\t\n";
    cout << "======================\n";

    cout << "Enter Customer Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, customerName);
    cout << '\n';

    do{
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cout << '\n';

    if (accountNumber.length() != 10) {
        cout << "Invalid account number! " << "It must contain at least 10 digits.\n\n";
    }
    }
    while(accountNumber.length() != 10);
    
    cout << "Enter Account Balance: ";
    cin >> currentBalance;
    cout << '\n';

    cout << "Enter PIN: ";
    cin >> PIN;
    cout << '\n';

    if(PIN != accessPIN){
        cout << "Incorrect Pin\n";
        return; //Break the program immediately
    }

    cout << "Enter Withdrawal Amount: ";
    cin >> withdrawalAmount;
    cout << '\n';

    //transaction exceeding 100,000
    if(withdrawalAmount > maximumWithdrawal){
        cout << "======================\n";
        cout << "TRANSACTION DECLINED\t\t\n";
        cout << "======================\n";
        cout << "Amount exceeds 100,000 Naira\n";
        return;
    }

    Customer customer = createCustomer(
        customerName, 
        accountNumber, 
        currentBalance, 
        accessPIN);

    if (withdrawalAmount >= largeWithdrawal){
        cout << "Notice: You are making a large withdrawal\n";
    }

    double bankCharge = bankChargeAmount(withdrawalAmount);
    double totalDebit = totalDebitAmount(withdrawalAmount, bankCharge);
    double updatedBalance = newBalance(customer.currentBalance, totalDebit);
    
    
    if(updatedBalance < minimumBalance){ 
        cout << "======================\n";
        cout << "TRANSACTION DECLINED\t\t\n";
        cout << "======================\n";
        cout << "Insufficient funds\n";
        return;
    }

    cout << "======================\n";
    cout << "TRANSACTION APPROVED\t\t\n";
    cout << "======================\n";

    cout << "Transaction ID: " << generateTransactionID();
    cout << '\n';

    cout << "Customer Name: " <<  customer.customerName;
    cout << '\n';

    cout << "Account Number: " << customer.accountNumber;
    cout << '\n';

    cout << "Previous Balance: N" << fixed << setprecision(2) << customer.currentBalance;
    cout << '\n';

    cout << "Withdrawal Amount: N" << fixed << setprecision(2) << withdrawalAmount;
    cout << '\n';

    cout << "Bank Charge (1%): N" << fixed << setprecision(2) << bankCharge;
    cout << '\n';

    cout << "Total Debit: N" << fixed << setprecision(2) << totalDebit;
    cout << '\n';
    
    cout << "New Balance: N" << fixed << setprecision(2) << updatedBalance;
    cout << '\n';

    cout << "======================\n";

}


int main(){

    srand(time(0)); //seed with time once
    int userChoice = 0;

    do{
    cout << "\nPress 1 to begin a transaction.\nPress 2 to exit\n";
    cin >> userChoice;

    switch(userChoice){
    case 1: handleDisplay(); break;
    case 2: cout  << "Thank you for using Smart ATM" << endl; break;

    default:
        cout << "Invalid option entered\n";
    }

    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid Input. Enter a number\n";
        continue;
    }
    }
    while(userChoice != 2);

    return 0;
}