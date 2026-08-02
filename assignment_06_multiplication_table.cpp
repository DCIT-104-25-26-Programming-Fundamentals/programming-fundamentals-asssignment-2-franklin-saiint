#include <iostream>
using namespace std;

void printSingleTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;
    for (int i = 1; i <= 12; ++i) {
        cout << number << " x " << i << " = " << (number * i) << endl;
    }
}

void printTablesUpToN(int n) {
    for (int table = 1; table <= n; ++table) {
        cout << "Multiplication Table for " << table << ":" << endl;
        for (int i = 1; i <= 12; ++i) {
            cout << table << " x " << i << " = " << (table * i) << endl;
        }
        if (table < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    printSingleTable(n);
    cout << endl;
    printTablesUpToN(n);

    return 0;
}

