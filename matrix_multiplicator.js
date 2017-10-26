function fillArray(arr) {
    for (let i = 0; i < arr.length; i++) {
        arr[i] = i;
    }
    return arr;
}

function createMatrix(dimension){
    return fillArray(Array(dimension)).map(
        function(n) {
            return fillArray(Array(dimension))
        })
    }

function printMatrix(matrix){
    matrix.map((n) => {
        console.log(n);
    })
}

function multiplyMatrix(matrixA, matrixB) {
    let dimension = matrixA.length;
    let matrixC = createMatrix(dimension);
    
    for(let i = 0; i < dimension; i++) {
        for (let j = 0; j < dimension; j++) {
            for (let k = 0; k < dimension; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return matrixC;
}

for (let i = 100; i < 2000; i += 100) {
    let matrixA = createMatrix(i);
    let matrixB = createMatrix(i);

    let start = Date.now();

    multiplyMatrix(matrixA, matrixB);

    let end = Date.now();

    console.log("n = " + i + '\n' + (end - start) + '\n');

}