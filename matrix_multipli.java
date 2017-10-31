public class MatrixMultiplicator {

    public MatrixMultiplicator() {
    }

    public void printMatrix(float[][] matrixA) {
        int size = matrixA[0].length;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print("[" + matrixA[i][j] + "]");
            }
            System.out.println("");
        }
    }

    public static float[][] multiplicate(float[][] matrixA, float[][] matrixB) {
        int size = matrixA[0].length;
        float[][] result = new float[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        float[][] matrixA, matrixB;
        long start, elapsedTime;

        for (int n = 100; n < 2000; n = n + 100) {
            matrixA = new float[n][n];
            matrixB = new float[n][n];
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    matrixA[j][k] = (float) Math.random();
                    matrixB[j][k] = (float) Math.random();
                }
            }
            start = System.nanoTime();
            multiplicate(matrixA, matrixB);
            elapsedTime = System.nanoTime() - start;
            System.out.println(elapsedTime);
        }
    }

}