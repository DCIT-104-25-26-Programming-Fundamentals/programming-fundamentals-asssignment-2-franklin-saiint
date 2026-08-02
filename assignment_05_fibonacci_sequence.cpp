#include <iostream>
using namespace std;

void printFibonacciSequence(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";
    if (n >= 1) {
        cout << 0;
    }
    if (n >= 2) {
        cout << " " << 1;
    }

    int first = 0;
    int second = 1;

    for (int i = 2; i < n; ++i) {
        int next = first + second;
        cout << " " << next;
        first = second;
        second = next;
    }

    cout << endl;
}

bool isFibonacci(int number) {
    if (number < 0) {
        return false;
    }
    if (number == 0 || number == 1) {
        return true;
    }

    int first = 0;
    int second = 1;

    while (second < number) {
        int next = first + second;
        first = second;
        second = next;
    }

    return second == number;
}

int main() {
    int n;
    int number;

    cout << "How many terms? ";
    cin >> n;
    printFibonacciSequence(n);

    cout << "Enter a number to check: ";
    cin >> number;

    if (isFibonacci(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}

