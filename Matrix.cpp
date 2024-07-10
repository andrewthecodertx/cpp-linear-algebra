#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>

Matrix::Matrix(const std::vector<std::vector<double>>& elements)
    : elements(elements), rows(elements.size()), cols(elements[0].size()) {}

size_t Matrix::numRows() const {
    return rows;
}

size_t Matrix::numCols() const {
    return cols;
}

double& Matrix::operator()(size_t row, size_t col) {
    return elements[row][col];
}

const double& Matrix::operator()(size_t row, size_t col) const {
    return elements[row][col];
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.numRows() || cols != other.numCols()) {
        throw std::invalid_argument("Matrices must be of the same dimensions");
    }
    std::vector<std::vector<double>> result(rows, std::vector<double>(cols));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = elements[i][j] + other(i, j);
        }
    }
    return Matrix(result);
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.numRows() || cols != other.numCols()) {
        throw std::invalid_argument("Matrices must be of the same dimensions");
    }
    std::vector<std::vector<double>> result(rows, std::vector<double>(cols));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = elements[i][j] - other(i, j);
        }
    }
    return Matrix(result);
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.numRows()) {
        throw std::invalid_argument("Number of columns of first matrix must equal number of rows of second matrix");
    }
    std::vector<std::vector<double>> result(rows, std::vector<double>(other.numCols()));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.numCols(); ++j) {
            result[i][j] = 0.0;
            for (size_t k = 0; k < cols; ++k) {
                result[i][j] += elements[i][k] * other(k, j);
            }
        }
    }
    return Matrix(result);
}

Matrix Matrix::transpose() const {
    std::vector<std::vector<double>> result(cols, std::vector<double>(rows));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[j][i] = elements[i][j];
        }
    }
    return Matrix(result);
}

void Matrix::print() const {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << elements[i][j] << " ";
        }
        std::cout << "\n";
    }
}

