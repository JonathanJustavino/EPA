#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float **createMatrix(int dim) {
    float **matrix;
    matrix = malloc(dim * sizeof(float *));
    
    for (int i = 0; i < dim; i++) {
        matrix[i] = malloc(dim * sizeof(float));
    }
    return matrix;
}

void fill(float **matrix, int dim, int offset) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            matrix[i][j] = fmod(0.1 * (i + j + offset), 1);
        }
    }
}

void print(float **matrix, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("[ %f ]", matrix[i][j]);
        }
        printf("\n");
    }
    printf("------------------------\n");
}

float **mult(float **matrixA, float **matrixB, int dim) {
    float **matrixC = createMatrix(dim);
    
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            for (int k = 0; k < dim; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return matrixC;
}

int main()
{
    float **matrixA, **matrixB;
    matrixA = createMatrix(2);
    matrixB = createMatrix(2);
    int dim = 2;
    
    fill(matrixA, dim, 0);
    fill(matrixB, dim, 1);
    
    print(matrixA, dim);
    print(matrixB, dim);
    
    float **matrixC = mult(matrixA, matrixB, dim);
    
    print(matrixC, dim);
    
    return 0;
}
