#include <iostream>
#include <vector>
#include <cmath>

class Vector {
private:
    std::vector<double> elements;

public:
    Vector(const std::vector<double>& elements) : elements(elements) {}

    size_t size() const {
        return elements.size();
    }

    double& operator[](size_t index) {
        return elements[index];
    }

    const double& operator[](size_t index) const {
        return elements[index];
    }

    Vector operator+(const Vector& other) const {
        if (size() != other.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        std::vector<double> result(size());
        for (size_t i = 0; i < size(); ++i) {
            result[i] = elements[i] + other[i];
        }
        return Vector(result);
    }

    Vector operator-(const Vector& other) const {
        if (size() != other.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        std::vector<double> result(size());
        for (size_t i = 0; i < size(); ++i) {
            result[i] = elements[i] - other[i];
        }
        return Vector(result);
    }

    Vector operator*(double scalar) const {
        std::vector<double> result(size());
        for (size_t i = 0; i < size(); ++i) {
            result[i] = elements[i] * scalar;
        }
        return Vector(result);
    }

    double dot(const Vector& other) const {
        if (size() != other.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        double result = 0.0;
        for (size_t i = 0; i < size(); ++i) {
            result += elements[i] * other[i];
        }
        return result;
    }

    double norm() const {
        double result = 0.0;
        for (const double& elem : elements) {
            result += elem * elem;
        }
        return std::sqrt(result);
    }

    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < size(); ++i) {
            std::cout << elements[i];
            if (i < size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
};

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
