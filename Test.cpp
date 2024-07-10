#include "Matrix.hpp"
#include "Vector.hpp"
#include <iostream>

void testVector() {
    std::vector<double> elems1 = {1.0, 2.0, 3.0};
    std::vector<double> elems2 = {4.0, 5.0, 6.0};

    Vector vec1(elems1);
    Vector vec2(elems2);

    Vector sum = vec1 + vec2;
    Vector diff = vec1 - vec2;
    Vector scaled = vec1 * 2.0;
    double dot_product = vec1.dot(vec2);
    double norm = vec1.norm();

    std::cout << "Vector tests:\n";
    std::cout << "vec1: ";
    vec1.print();
    std::cout << "vec2: ";
    vec2.print();
    std::cout << "sum: ";
    sum.print();
    std::cout << "diff: ";
    diff.print();
    std::cout << "scaled: ";
    scaled.print();
    std::cout << "dot product: " << dot_product << "\n";
    std::cout << "norm: " << norm << "\n";
}

void testMatrix() {
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

    std::cout << "Matrix tests:\n";
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

int main() {
    testVector();
    testMatrix();
}
