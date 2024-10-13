# Parallel Matrix Multiplication and Convolution
This repository contains a C++ program that demonstrates parallelized matrix multiplication and convolution using OpenMP. The goal is to compare the performance of sequential and parallel executions, providing insights into the efficiency of parallel computing for matrix operations.


## Features
- Implements sequential and parallel matrix multiplication.
- Implements sequential and parallel convolution methods.
- Measures execution time for different matrix sizes (10x10, 50x50, 100x100, and 500x500).
- Compares performance across various thread configurations (1, 2, 4, and 8 threads).
- Outputs execution time in milliseconds with two decimal precision.

## Files
- **matrix_multiplication_openmp.cpp**: The main program implementing both sequential and parallel matrix multiplication.

## Requirements
- C++ compiler supporting OpenMP (e.g., GCC)
- OpenMP library

## Usage

### Compilation
To compile the program, ensure OpenMP is enabled in your compiler. You can use the following command:

```bash
g++ -o matrix_multiplication_openmp matrix_multiplication_openmp.cpp -fopenmp
```

### Running
After compiling, run the program:

```bash
./matrix_multiplication_openmp
```

### Expected Output
The program will output the time taken (in milliseconds) for both sequential and parallel execution across different matrix sizes, like this:

```
Matrix Size: 10x10
Sequential time taken: 0.03 ms
Parallel (1 threads) version time taken: 0.16 ms
Parallel (2 threads) version time taken: 0.15 ms
Parallel (4 threads) version time taken: 0.16 ms
Parallel (8 threads) version time taken: 0.85 ms
--------------------------
Sequential Convolution time taken: 0.01 ms
Parallel Convolution (1 threads) version time taken: 0.02 ms
Parallel Convolution (2 threads) version time taken: 0.01 ms
Parallel Convolution (4 threads) version time taken: 0.20 ms
Parallel Convolution (8 threads) version time taken: 7.43 ms
--------------------------
Matrix Size: 50x50
Sequential time taken: 2.12 ms
Parallel (1 threads) version time taken: 2.24 ms
Parallel (2 threads) version time taken: 1.61 ms
Parallel (4 threads) version time taken: 1.82 ms
Parallel (8 threads) version time taken: 1.28 ms
--------------------------
Sequential Convolution time taken: 0.58 ms
Parallel Convolution (1 threads) version time taken: 0.51 ms
Parallel Convolution (2 threads) version time taken: 0.22 ms
Parallel Convolution (4 threads) version time taken: 0.46 ms
Parallel Convolution (8 threads) version time taken: 0.30 ms
--------------------------
Matrix Size: 100x100
Sequential time taken: 18.81 ms
Parallel (1 threads) version time taken: 12.42 ms
Parallel (2 threads) version time taken: 10.76 ms
Parallel (4 threads) version time taken: 4.99 ms
Parallel (8 threads) version time taken: 4.61 ms
--------------------------
Sequential Convolution time taken: 1.76 ms
Parallel Convolution (1 threads) version time taken: 3.69 ms
Parallel Convolution (2 threads) version time taken: 2.14 ms
Parallel Convolution (4 threads) version time taken: 0.99 ms
Parallel Convolution (8 threads) version time taken: 7.02 ms
--------------------------
Matrix Size: 500x500
Sequential time taken: 1311.48 ms
Parallel (1 threads) version time taken: 1445.82 ms
Parallel (2 threads) version time taken: 747.21 ms
Parallel (4 threads) version time taken: 562.73 ms
Parallel (8 threads) version time taken: 560.61 ms
--------------------------
Sequential Convolution time taken: 37.76 ms
Parallel Convolution (1 threads) version time taken: 25.32 ms
Parallel Convolution (2 threads) version time taken: 16.97 ms
Parallel Convolution (4 threads) version time taken: 15.61 ms
Parallel Convolution (8 threads) version time taken: 13.07 ms
```

## Performance Analysis
For smaller matrix sizes (like `10x10` and `50x50`), sequential execution may outperform parallel execution due to thread management overhead. However, as matrix sizes grow larger (e.g., `100x100`, `500x500`), parallel execution generally becomes faster with increasing thread count.

## Further Reading
- [OpenMP Documentation](https://www.openmp.org/specifications/)

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
