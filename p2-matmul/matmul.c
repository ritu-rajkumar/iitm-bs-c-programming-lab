#include <stdio.h>
#include <time.h>

// while compiling use -D DIM=5 to change the dimensions to 5
#ifndef DIM
#define DIM 3
#endif

/// @brief Reads the matrix from a space separated text file.
/// @param filename Path to the file
/// @param A 2D array of dimension DIMxDIM defined by the DIM macro.
void read_mat(char *filename, float A[DIM][DIM])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            fscanf(file, "%f", &A[i][j]);
        }
    }
    fclose(file);
}

/**
 * @brief print a Matrix in rows and columns
 *
 * @param A: 2-D matrix
 *
 * Print the matrix out so that each row is on one line.  Example:
 * A[0][0] A[0][1] A[0][2]
 * A[1][0] A[1][1] ... etc.
 */
void print_mat(float A[DIM][DIM])
{
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
}

/// @brief Performs the matrix multiplication on Matrix A and B and saves the results to Matrix C
/// @param A Input Matrix A
/// @param B Input Matrix B
/// @param C Output Matrix C
void matmul(float A[DIM][DIM], float B[DIM][DIM], float C[DIM][DIM])
{
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            C[i][j] = 0; // Initialize the result matrix
            for (int k = 0; k < DIM; k++) {
                C[i][j] += A[i][k] * B[k][j]; // Perform multiplication
            }
        }
    }
}

double gettime()
{
    return (double)clock() / CLOCKS_PER_SEC; // Return time in seconds
}

int main()
{
    float A[DIM][DIM];
    float B[DIM][DIM];
    float C[DIM][DIM];

    // Task 1: Read Matrix A and B and print them
    printf("Dimension of the matrices: %d\n", DIM);

    read_mat("a.txt", A);
    read_mat("b.txt", B);

    printf("Matrix A: \n");
    print_mat(A);

    printf("Matrix B: \n");
    print_mat(B);

    // Task 2: Perform Matrix multiplication
    // Uncomment the below part after doing task 1.

    double t1 = gettime();
    // Declare a matrix C and use it for multiplication
    matmul(A, B, C);
    double t2 = gettime();
    printf("Matrix C: \n");
    print_mat(C);

    printf("Time taken: %8.4g milliseconds\n", (t2-t1)*1000);
}