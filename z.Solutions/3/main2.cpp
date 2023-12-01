#include <iostream>

using namespace std;

class Matrix {
private:
    double matrix[4][4];

public:
    Matrix();

    ~Matrix();

    void readMatrix();

    void printMatrix();

    // Transpose the matrix.
    Matrix transpose();

    // Calculate the determinant of the matrix.
    double determinant(double pDouble[4][4], int i, int i1);

    // Calculate the inverse of the matrix.
    Matrix inverse();
};

Matrix::Matrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = 0.0;
        }
    }
}

Matrix::~Matrix() {
    // Nothing to do here.
}

void Matrix::readMatrix() {
    cout << "Enter the matrix elements: " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> matrix[i][j];
        }
    }
}

void Matrix::printMatrix() {
    cout << "The matrix is: " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::transpose() {
    Matrix transposeMatrix;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            transposeMatrix.matrix[j][i] = matrix[i][j];
        }
    }

    return transposeMatrix;
}

double Matrix::determinant(double pDouble[4][4], int i, int i1) {
    double determinant = 1.0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0.0) {
                double factor = matrix[i][j] / matrix[j][j];
                for (int k = j; k < 4; k++) {
                    matrix[i][k] -= factor * matrix[j][k];
                }
            }
        }

        if (matrix[i][i] == 0.0) {
            return 0.0;
        }

        determinant *= matrix[i][i];
    }

    return determinant;
}

int main() {
    Matrix matrix;
    matrix.readMatrix();

    cout << "The transpose of the matrix is: " << endl;
    matrix.transpose().printMatrix();

    cout << "The determinant of the matrix is: " << endl;
    cout << matrix.determinant(nullptr, 0, 0) << endl;

    return 1;
}