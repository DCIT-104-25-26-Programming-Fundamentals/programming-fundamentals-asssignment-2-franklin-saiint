#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        return NAN;
    }
    return a / b;
}

double calculateModulus(double a, double b) {
    if (b == 0) {
        return NAN;
    }
    return fmod(a, b);
}

double exponentiate(double a, double b) {
    return pow(a, b);
}

int main() {
    int choice;
    double a, b;

    while (true) {
        cout << "============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        double result;
        if (choice == 1) {
            result = add(a, b);
            cout << "Result: " << a << " + " << b << " = " << fixed << setprecision(2) << result << endl;
        } else if (choice == 2) {
            result = subtract(a, b);
            cout << "Result: " << a << " - " << b << " = " << fixed << setprecision(2) << result << endl;
        } else if (choice == 3) {
            result = multiply(a, b);
            cout << "Result: " << a << " * " << b << " = " << fixed << setprecision(2) << result << endl;
        } else if (choice == 4) {
            if (b == 0) {
                cout << "Error: Cannot divide by zero." << endl;
            } else {
                result = divide(a, b);
                cout << "Result: " << a << " / " << b << " = " << fixed << setprecision(2) << result << endl;
            }
        } else if (choice == 5) {
            if (b == 0) {
                cout << "Error: Cannot divide by zero." << endl;
            } else {
                result = calculateModulus(a, b);
                cout << "Result: " << a << " % " << b << " = " << fixed << setprecision(2) << result << endl;
            }
        } else if (choice == 6) {
            result = exponentiate(a, b);
            cout << "Result: " << a << " ^ " << b << " = " << fixed << setprecision(2) << result << endl;
        } else {
            cout << "Error: Invalid choice." << endl;
        }
    }

    return 0;
}

