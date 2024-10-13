#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>
#include <iomanip>  // For std::setprecision

using namespace std;
using namespace chrono;

// Function to perform sequential matrix multiplication
void sequentialMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to perform parallel matrix multiplication using OpenMP
void parallelMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C, int n, int num_threads) {
    #pragma omp parallel for num_threads(num_threads) collapse(2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to print the time difference in milliseconds with two decimal precision
void printTimeTaken(string method, steady_clock::time_point start, steady_clock::time_point end) {
    auto duration = duration_cast<chrono::duration<double, milli>>(end - start).count();
    cout << method << " time taken: " << fixed << setprecision(2) << duration << " ms" << endl;
}

int main() {
    vector<int> sizes = {10, 50, 100, 500};
    
    for (int n : sizes) {
        cout << "Matrix Size: " << n << "x" << n << endl;
        
        // Initialize matrices
        vector<vector<int>> A(n, vector<int>(n, 1));  // A filled with 1's
        vector<vector<int>> B(n, vector<int>(n, 2));  // B filled with 2's
        vector<vector<int>> C(n, vector<int>(n, 0));  // Result matrix
        
        // Sequential Multiplication
        auto start = steady_clock::now();
        sequentialMultiply(A, B, C, n);
        auto end = steady_clock::now();
        printTimeTaken("Sequential", start, end);
        
        // Parallel Multiplication for different thread counts
        for (int num_threads : {1, 2, 4, 8}) {
            start = steady_clock::now();
            parallelMultiply(A, B, C, n, num_threads);
            end = steady_clock::now();
            cout << "Parallel (" << num_threads << " threads) ";
            printTimeTaken("version", start, end);
        }
        
        cout << "--------------------------" << endl;
    }
    
    return 0;
}
