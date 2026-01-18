#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double inputStartingBalance() {
    double startBalance;
    cout << "Provide starting balance of the account: ";
    cin >> startBalance;

    while (startBalance <= 0) {
        cout << "Balance must be greater than zero.\n";
        cout << "Re-enter starting balance: ";
        cin >> startBalance;
    }
    return startBalance;
}

int inputTotalMonths() {
    int totalMonths;
    cout << "Enter number of months account has been active: ";
    cin >> totalMonths;

    while (totalMonths < 1) {
        cout << "Months must be at least 1.\n";
        cout << "Re-enter total months: ";
        cin >> totalMonths;
    }
    return totalMonths;
}

double inputTransaction(const string& promptMsg) {
    double value;
    do {
        cout << promptMsg;
        cin >> value;
        if (value < 0)
            cout << "Error: Negative values are not allowed.\n";
    } while (value < 0);

    return value;
}

double computeMonthlyDeduction(double currentBalance, double ratePerMonth) {
    return currentBalance * ratePerMonth;
}

int main() {
    double yearlyTaxRate;
    double accountBalance;

    accountBalance = inputStartingBalance();

    cout << "Enter yearly tax deduction percentage: ";
    cin >> yearlyTaxRate;

    while (yearlyTaxRate < 0) {
        cout << "Tax rate cannot be negative. Enter again: ";
        cin >> yearlyTaxRate;
    }

    int monthCount = inputTotalMonths();

    double monthlyRate = (yearlyTaxRate / 100) / 12;

    double depositRecord[monthCount];
    double withdrawalRecord[monthCount];
    double taxRecord[monthCount];

    double sumDeposits = 0;
    double sumWithdrawals = 0;
    double sumTax = 0;

    for (int m = 0; m < monthCount; m++) {
        cout << "\n=== Processing Month " << m + 1 << " ===\n";

        depositRecord[m] = inputTransaction("Enter deposit for this month: ");
        accountBalance += depositRecord[m];
        sumDeposits += depositRecord[m];

        withdrawalRecord[m] = inputTransaction("Enter withdrawal for this month: ");
        accountBalance -= withdrawalRecord[m];
        sumWithdrawals += withdrawalRecord[m];

        taxRecord[m] = computeMonthlyDeduction(accountBalance, monthlyRate);
        accountBalance -= taxRecord[m];
        sumTax += taxRecord[m];
    }

    cout << "\n******** ACCOUNT REPORT ********\n";
    cout << fixed << setprecision(2);
    cout << "Ending Balance:        " << accountBalance << endl;
    cout << "Total Deposits:        " << sumDeposits << endl;
    cout << "Total Withdrawals:     " << sumWithdrawals << endl;
    cout << "Total Tax Deducted:    " << sumTax << endl;

    cout << "\nProgram execution completed successfully.\n";

    return 0;
}
