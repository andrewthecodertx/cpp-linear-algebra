#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
private:
    std::vector<std::vector<double>> elements;
    size_t rows;
    size_t cols;

public:
    // Constructor
    Matrix(const std::vector<std::vector<double>>& elements);

    // Get number of rows
    size_t numRows() const;

    // Get number of columns
    size_t numCols() const;

    // Access elements
    double& operator()(size_t row, size_t col);
    const double& operator()(size_t row, size_t col) const;

    // Matrix addition
    Matrix operator+(const Matrix& other) const;

    // Matrix subtraction
    Matrix operator-(const Matrix& other) const;

    // Matrix multiplication
    Matrix operator*(const Matrix& other) const;

    // Transpose
    Matrix transpose() const;

    // Print matrix
    void print() const;
};

#endif // MATRIX_H
