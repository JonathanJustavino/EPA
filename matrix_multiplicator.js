"use strict";

function fillArray(arr) {
    for (let i = 0; i < arr.length; i++) {
        arr[i] = i;
    }
    return arr;
}

function createMatrix(dimension){
    return fillArray(Array(dimension)).map(
        function(n) {
            return fillArray(new Float64Array(dimension))
        })
    }

function printMatrix(matrix){
    matrix.map((n) => {
        console.log(n);
    })
}

function multiplyMatrix(matrixA, matrixB) {
    let dim = matrixA.length;
    let matrixC = createMatrix(dim);
    
    for (let i = dim; --i >= 0;) {
        let matrix_c_i = matrixC[i];
        let matrixA_i = matrixA[i];
        for (let j = dim; --j >= 0;) {
            let matrix_c_i_j = 0;
            for (let k = dim; --k >= 0;) {
                matrix_c_i_j += matrixA_i[k] * matrixB[k][j];
            }
            matrix_c_i[j] = matrix_c_i_j;
        }
    }
    return matrixC;
}

for (let i = 100; i <= 2000; i += 100) {
    let matrixA = createMatrix(i);
    let matrixB = createMatrix(i);

    let start = Date.now();

    multiplyMatrix(matrixA, matrixB);

    let end = Date.now();

    console.log("Dim = " + i + '\n' + ((end - start)/1000) + ' s' + '\n');

}