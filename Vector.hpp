#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <cstddef>

class Vector {
private:
    std::vector<double> elements;

public:
    // Constructor
    Vector(const std::vector<double>& elements);

    // Get vector size
    size_t size() const;

    // Access elements
    double& operator[](size_t index);
    const double& operator[](size_t index) const;

    // Vector addition
    Vector operator+(const Vector& other) const;

    // Vector subtraction
    Vector operator-(const Vector& other) const;

    // Scalar multiplication
    Vector operator*(double scalar) const;

    // Dot product
    double dot(const Vector& other) const;

    // Norm (L2)
    double norm() const;

    // Print vector
    void print() const;
};

#endif // VECTOR_H
