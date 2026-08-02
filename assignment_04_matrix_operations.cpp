#include <iostream>
#include <iomanip>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(const int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(const int matrix[10][10], int transpose[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(const int a[10][10], const int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(const int a[10][10], const int b[10][10], int result[10][10], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            int sum = 0;
            for (int k = 0; k < colsA; ++k) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    int choice;
    int rows, cols, rowsB, colsB;
    int matrixA[10][10], matrixB[10][10], result[10][10];

    cout << "Choose an operation:" << endl;
    cout << "1. Transpose matrix" << endl;
    cout << "2. Add two matrices" << endl;
    cout << "3. Multiply two matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(matrixA, rows, cols);
        cout << "Original Matrix:" << endl;
        displayMatrix(matrixA, rows, cols);

        transposeMatrix(matrixA, result, rows, cols);
        cout << "Transposed Matrix:" << endl;
        displayMatrix(result, cols, rows);
    } else if (choice == 2) {
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Enter matrix A:" << endl;
        readMatrix(matrixA, rows, cols);
        cout << "Enter matrix B:" << endl;
        readMatrix(matrixB, rows, cols);

        addMatrices(matrixA, matrixB, result, rows, cols);
        cout << "Result Matrix:" << endl;
        displayMatrix(result, rows, cols);
    } else if (choice == 3) {
        cout << "Enter number of rows for matrix A: ";
        cin >> rows;
        cout << "Enter number of columns for matrix A: ";
        cin >> cols;
        cout << "Enter number of rows for matrix B: ";
        cin >> rowsB;
        cout << "Enter number of columns for matrix B: ";
        cin >> colsB;

        if (cols != rowsB) {
            cout << "Error: Number of columns in A must equal number of rows in B." << endl;
            return 0;
        }

        cout << "Enter matrix A:" << endl;
        readMatrix(matrixA, rows, cols);
        cout << "Enter matrix B:" << endl;
        readMatrix(matrixB, rowsB, colsB);

        multiplyMatrices(matrixA, matrixB, result, rows, cols, rowsB, colsB);
        cout << "Product Matrix:" << endl;
        displayMatrix(result, rows, colsB);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

