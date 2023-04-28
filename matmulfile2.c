#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in, *out;
    int **mA, **mB, **mC;
    int rA, cA, rB, cB, i, j, k;

    // Open input file for reading
    in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Failed to open input file.\n");
        exit(1);
    }

    // Read matrix A dimensions from input file
    fscanf(in, "%d %d", &rA, &cA);

    // Read matrix B dimensions from input file
    fscanf(in, "%d %d", &rB, &cB);

    // Check if matrices can be multiplied
    if (cA != rB) {
        printf("Matrix multiplication is not possible.\n");
        exit(1);
    }

    // Allocate memory for matrices A, B, and C
    mA = (int **) malloc(rA * sizeof(int *));
    for (i = 0; i < rA; i++) {
        mA[i] = (int *) malloc(cA * sizeof(int));
    }

    mB = (int **) malloc(rB * sizeof(int *));
    for (i = 0; i < rB; i++) {
        mB[i] = (int *) malloc(cB * sizeof(int));
    }

    mC = (int **) malloc(rA * sizeof(int *));
    for (i = 0; i < rA; i++) {
        mC[i] = (int *) malloc(cB * sizeof(int));
    }

    // Read matrix A from input file
    for (i = 0; i < rA; i++) {
        for (j = 0; j < cA; j++) {
            fscanf(in, "%d", &mA[i][j]);
        }
    }

    // Read matrix B from input file
    for (i = 0; i < rB; i++) {
        for (j = 0; j < cB; j++) {
            fscanf(in, "%d", &mB[i][j]);
        }
    }

    // Compute matrix multiplication
    for (i = 0; i < rA; i++) {
        for (j = 0; j < cB; j++) {
            mC[i][j] = 0;
            for (k = 0; k < cA; k++) {
                mC[i][j] += mA[i][k] * mB[k][j];
            }
        }
    }

    // Open output file for writing
    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Failed to open output file.\n");
        exit(1);
    }

    // Write matrix C (result) to output file
    for (i = 0; i < rA; i++) {
        for (j = 0; j < cB; j++) {
            fprintf(out, "%d ", mC[i][j]);
        }
        fprintf(out, "\n");
    }
    }

    
