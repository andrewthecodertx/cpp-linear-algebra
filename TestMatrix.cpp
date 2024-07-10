#include "Matrix.hpp"
#include <iostream>

int main() {
    std::vector<std::vector<double>> elems1 = {{1.0, 2.0, 3.0},
                                               {4.0, 5.0, 6.0}};
    std::vector<std::vector<double>> elems2 = {{7.0, 8.0},
                                               {9.0, 10.0},
                                               {11.0, 12.0}};

    Matrix mat1(elems1);
    Matrix mat2(elems2);

    Matrix sum = mat1 + mat1; // Adding mat1 to itself for demonstration
    Matrix diff = mat1 - mat1; // Subtracting mat1 from itself for demonstration
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

    return 0;
}
