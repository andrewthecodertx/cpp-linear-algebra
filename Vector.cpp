#include "Vector.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

Vector::Vector(const std::vector<double>& elements)
    : elements(elements) {}

size_t Vector::size() const {
    return elements.size();
}

double& Vector::operator[](size_t index) {
    return elements[index];
}

const double& Vector::operator[](size_t index) const {
    return elements[index];
}

Vector Vector::operator+(const Vector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vectors must be of the same size");
    }
    std::vector<double> result(size());
    for (size_t i = 0; i < size(); ++i) {
        result[i] = elements[i] + other[i];
    }
    return Vector(result);
}

Vector Vector::operator-(const Vector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vectors must be of the same size");
    }
    std::vector<double> result(size());
    for (size_t i = 0; i < size(); ++i) {
        result[i] = elements[i] - other[i];
    }
    return Vector(result);
}

Vector Vector::operator*(double scalar) const {
    std::vector<double> result(size());
    for (size_t i = 0; i < size(); ++i) {
        result[i] = elements[i] * scalar;
    }
    return Vector(result);
}

double Vector::dot(const Vector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vectors must be of the same size");
    }
    double result = 0.0;
    for (size_t i = 0; i < size(); ++i) {
        result += elements[i] * other[i];
    }
    return result;
}

double Vector::norm() const {
    double result = 0.0;
    for (const double& elem : elements) {
        result += elem * elem;
    }
    return std::sqrt(result);
}

void Vector::print() const {
    std::cout << "[";
    for (size_t i = 0; i < size(); ++i) {
        std::cout << elements[i];
        if (i < size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}
