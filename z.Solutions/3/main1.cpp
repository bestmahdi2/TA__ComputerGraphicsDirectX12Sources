#include <iostream>

using namespace std;

const int MATRIX_SIZE = 4;

void add_matrices(int a[][MATRIX_SIZE], int b[][MATRIX_SIZE], int c[][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract_matrices(int a[][MATRIX_SIZE], int b[][MATRIX_SIZE], int c[][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiply_matrices(int a[][MATRIX_SIZE], int b[][MATRIX_SIZE], int c[][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            c[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    // matrix a
    int a[MATRIX_SIZE][MATRIX_SIZE] = {{1,  2,  3,  4},
                                       {5,  6,  7,  8},
                                       {9,  10, 11, 12},
                                       {13, 14, 15, 16}};

    // matrix b
    int b[MATRIX_SIZE][MATRIX_SIZE] = {{16, 15, 14, 13},
                                       {12, 11, 10, 9},
                                       {8,  7,  6,  5},
                                       {4,  3,  2,  1}};

    // matrix c to save the results
    int c[MATRIX_SIZE][MATRIX_SIZE];

    // Add matrices
    add_matrices(a, b, c);

    // print results
    cout << "Addition of matrices:" << endl;
    for (auto & i : c) { // for (int i = 0; i < MATRIX_SIZE; i++) {
        cout << "| ";
        for (int j : i) {
            cout << j << " ";
        }
        cout << "|" << endl;
    }

    // empty c matrix
    fill(&c[0][0], &c[0][0] + sizeof(c) / sizeof(**c), 0);

    // Subtract matrices
    subtract_matrices(a, b, c);

    // print results
    cout << endl << "Subtraction of matrices:" << endl;
    for (auto & i : c) {
        cout << "| ";
        for (int j : i) {
            cout << j << " ";
        }
        cout << "|" << endl;
    }

    // empty c matrix
    fill(&c[0][0], &c[0][0] + sizeof(c) / sizeof(**c), 0);

    // Multiply matrices
    multiply_matrices(a, b, c);
    cout << endl << "Multiplication of matrices:" << endl;

    // print results
    for (auto & i : c) {
        cout << "| ";
        for (int j : i) {
            cout << j << " ";
        }
        cout << "|" << endl;
    }

    return 0;
}
