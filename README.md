
# Parallel Matrix Multiplication with OpenMP

This repository contains a C++ program that implements matrix multiplication using both sequential and parallel approaches. The parallel version uses OpenMP to demonstrate the impact of multi-threading on performance across different matrix sizes.

## Features
- Matrix multiplication for square matrices of sizes: `10x10`, `50x50`, `100x100`, `500x500`.
- Comparison of sequential and parallel execution using multiple thread counts: `1, 2, 4, 8`.
- Timing results displayed in milliseconds (ms) with two decimal precision.

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
Sequential time taken: 0.01 ms
Parallel (1 threads) version time taken: 0.02 ms
Parallel (2 threads) version time taken: 0.35 ms
Parallel (4 threads) version time taken: 0.13 ms
Parallel (8 threads) version time taken: 0.21 ms
--------------------------
Matrix Size: 50x50
Sequential time taken: 2.91 ms
Parallel (1 threads) version time taken: 2.27 ms
Parallel (2 threads) version time taken: 0.93 ms
Parallel (4 threads) version time taken: 1.36 ms
Parallel (8 threads) version time taken: 8.62 ms
--------------------------
Matrix Size: 100x100
Sequential time taken: 22.24 ms
Parallel (1 threads) version time taken: 13.12 ms
Parallel (2 threads) version time taken: 5.91 ms
Parallel (4 threads) version time taken: 6.94 ms
Parallel (8 threads) version time taken: 11.23 ms
--------------------------
Matrix Size: 500x500
Sequential time taken: 1322.49 ms
Parallel (1 threads) version time taken: 1464.83 ms
Parallel (2 threads) version time taken: 1001.15 ms
Parallel (4 threads) version time taken: 620.36 ms
Parallel (8 threads) version time taken: 543.81 ms
--------------------------
```

## Performance Analysis
For smaller matrix sizes (like `10x10` and `50x50`), sequential execution may outperform parallel execution due to thread management overhead. However, as matrix sizes grow larger (e.g., `100x100`, `500x500`), parallel execution generally becomes faster with increasing thread count.

## Further Reading
- [OpenMP Documentation](https://www.openmp.org/specifications/)

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
