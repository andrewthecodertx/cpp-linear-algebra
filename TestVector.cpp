#include "Vector.hpp"
#include <iostream>

int main() {
    std::vector<double> elems1 = {1.0, 2.0, 3.0};
    std::vector<double> elems2 = {4.0, 5.0, 6.0};

    Vector vec1(elems1);
    Vector vec2(elems2);

    Vector sum = vec1 + vec2;
    Vector diff = vec1 - vec2;
    Vector scaled = vec1 * 2.0;
    double dot_product = vec1.dot(vec2);
    double norm = vec1.norm();

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
