# C++ Linear Algebra Library

A lightweight and simple C++ library for performing linear algebra operations, designed primarily for use in neural network programming and mathematical computations.

## Features

- **Matrix and Vector Operations:** Includes basic matrix and vector classes for common linear algebra operations.
- **Modular Design:** Header (`.hpp`) and source (`.cpp`) files are provided for easy integration and modification.
- **Testing Support:** A `Test.cpp` file is included to verify the functionality of the library.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`, `clang++`).
- `make` for building the project (optional but recommended).

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/andrewthecodertx/cpp-linear-algebra.git
   ```
2. Navigate to the project directory:
   ```bash
   cd cpp-linear-algebra
   ```

### Building the Project

Use the included `Makefile` to build the library and test executable:

```bash
make
```

### Running Tests

After building, run the tests to verify the library's functionality:

```bash
./test
```

## Usage

Include the headers in your project to use the matrix and vector classes:

```cpp
#include "Matrix.hpp"
#include "Vector.hpp"

int main() {
    // Example: Creating and manipulating a matrix
    Matrix mat(2, 2);
    mat(0, 0) = 1;
    mat(0, 1) = 2;
    mat(1, 0) = 3;
    mat(1, 1) = 4;

    mat.print();

    return 0;
}
```

Compile your program with the library files:

```bash
g++ -o example main.cpp Matrix.cpp Vector.cpp
```

## File Structure

- `Matrix.hpp` and `Matrix.cpp`: Definitions and implementations for matrix operations.
- `Vector.hpp` and `Vector.cpp`: Definitions and implementations for vector operations.
- `Test.cpp`: Test cases for validating the library.
- `Makefile`: Automates the build process.

## Contributions

Contributions are welcome! If you'd like to improve this library or add new features, feel free to fork the repository and open a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Author

Created by [Andrew the Coder](https://andrewthecoder.xyz).

---

