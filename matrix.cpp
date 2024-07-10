#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<double>> elements;
    size_t rows;
    size_t cols;

public:
    Matrix(const std::vector<std::vector<double>>& elements)
        : elements(elements), rows(elements.size()), cols(elements[0].size()) {}

    size_t numRows() const {
        return rows;
    }

    size_t numCols() const {
        return cols;
    }

    double& operator()(size_t row, size_t col) {
        return elements[row][col];
    }

    const double& operator()(size_t row, size_t col) const {
        return elements[row][col];
    }

    Matrix operator+(const Matrix& other) const {
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

    Matrix operator-(const Matrix& other) const {
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

    Matrix operator*(const Matrix& other) const {
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

    Matrix transpose() const {
        std::vector<std::vector<double>> result(cols, std::vector<double>(rows));
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[j][i] = elements[i][j];
            }
        }
        return Matrix(result);
    }

    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << elements[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    std::vector<std::vector<double>> elems1 = {{1.0, 2.0, 3.0},
                                               {4.0, 5.0, 6.0}};
    std::vector<std::vector<double>> elems2 = {{7.0, 8.0},
                                               {9.0, 10.0},
                                               {11.0, 12.0}};

    Matrix mat1(elems1);
    Matrix mat2(elems2);

    Matrix sum = mat1 + mat1; 
    Matrix diff = mat1 - mat1; 
    Matrix prod = mat1 * mat2;
    Matrix trans = mat1.transpose();

    std::cout << "mat1:\n";
    mat1.print();
    std::cout << "mat2:\n";
    mat2.print();
    std::cout << "sum:\n";
    sum.print();
    std::cout << "diff:\n";
    diff.print();
    std::cout << "prod:\n";
    prod.print();
    std::cout << "transpose of mat1:\n";
    trans.print();
}
