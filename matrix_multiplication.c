#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double **createMatrix2(int dim) {
    double **matrix;
    matrix = malloc(dim * sizeof(double *));
    
    for (int i = 0; i < dim; i++) {
        matrix[i] = malloc(dim * sizeof(double));
    }
    return matrix;
}

double **createMatrix(int dim) {
    int mem_size = (dim * dim * sizeof(double)) + dim * sizeof(double **);
    
    char *memory = malloc(mem_size);
    double **matrix = (double **)memory;
    
    double *start_pointer = (double *)(memory + dim * (sizeof(double **)));
    
    for (int i = 0; i < dim; i++) {
        matrix[i] = start_pointer + i * dim;
    }
    return matrix;
}

void deleteMatrix(double **matrix, int dim) {
    free(matrix);
}

void deleteMatrix2(double **matrix, int dim) {
    for (int i = 0; i < dim; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill(double **matrix, int dim, int offset) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            matrix[i][j] = fmod(0.1 * (i + j + offset), 1);
        }
    }
}

void print(double **matrix, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("[ %f ]", matrix[i][j]);
        }
        printf("\n");
    }
    printf("------------------------\n");
}

double **mult(double **matrixA, double **matrixB, int dim) {
    double **matrixC = createMatrix(dim);
    
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
    
//    double **matrixA, **matrixB;
//    matrixA = createMatrix2(2);
//    matrixB = createMatrix2(2);
//    int dim = 2;
//
//    fill(matrixA, dim, 0);
//    fill(matrixB, dim, 1);
//
//    print(matrixA, dim);
//    print(matrixB, dim);
//
//    double **matrixC = mult(matrixA, matrixB, dim);
//
//    print(matrixC, dim);
//
//    int time_local = (int)time(NULL);
//    int time_local2 = (int)time(NULL);
//
//    printf("Timestamp: %d\n",(time_local2 - time_local));
    
    for(int i = 100; i < 2000; i+=100) {
        printf("\n Dim = %i \n", i);
        double **matrixA, **matrixB;
        
        clock_t time_create_start = clock();
        
        matrixA = createMatrix(i);
        matrixB = createMatrix(i);

        clock_t time_create_end = clock();
        
        fill(matrixA, i, 0);
        fill(matrixB, i, 1);

        clock_t time_start = clock();

        double **matrixC = mult(matrixA, matrixB, i);

        clock_t time_end = clock();

        printf("Calc_Time: %f s \n", ((float)(time_end - time_start)) / 1000000);
        
        deleteMatrix(matrixA, i);
        deleteMatrix(matrixB, i);
        deleteMatrix(matrixC, i);

    }
    
    return 0;
}
