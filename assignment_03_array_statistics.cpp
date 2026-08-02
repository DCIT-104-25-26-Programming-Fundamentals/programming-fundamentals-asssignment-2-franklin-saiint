#include <iostream>
#include <iomanip>
using namespace std;

int calculateSum(const int numbers[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i];
    }
    return sum;
}

double calculateAverage(const int numbers[], int n) {
    return static_cast<double>(calculateSum(numbers, n)) / n;
}

int calculateMaximum(const int numbers[], int n) {
    int maximum = numbers[0];
    for (int i = 1; i < n; ++i) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    return maximum;
}

int calculateMinimum(const int numbers[], int n) {
    int minimum = numbers[0];
    for (int i = 1; i < n; ++i) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    return minimum;
}

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    int numbers[100];

    for (int i = 0; i < n; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << endl << "Results:" << endl;
    cout << "Sum:     " << calculateSum(numbers, n) << endl;
    cout << fixed << setprecision(1);
    cout << "Average: " << calculateAverage(numbers, n) << endl;
    cout << defaultfloat;
    cout << "Maximum: " << calculateMaximum(numbers, n) << endl;
    cout << "Minimum: " << calculateMinimum(numbers, n) << endl;

    return 0;
}

