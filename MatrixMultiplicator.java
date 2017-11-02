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
        float[][] matrixC = new float[size][size];
        for (int i = size; --i >= 0;) {
            float[] matrixA_i = matrixA[i];
            float[] matrixC_i = matrixC[i];
            for (int j = size; --j >= 0;) {
                float matrixC_i_j = 0;
                for (int k = size; --k >= 0;) {
                    matrixC_i_j += matrixA[i][k] * matrixB[k][j];
                }
                matrixC_i[j] = matrixC_i_j;
            }
        }
        return matrixC;
    }

    public static void main(String[] args) {
        float[][] matrixA, matrixB;
        long start;
        double elapsedTime;

        for (int n = 100; n <= 2000; n = n + 100) {
            matrixA = new float[n][n];
            matrixB = new float[n][n];
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    matrixA[j][k] = (float) Math.random();
                    matrixB[j][k] = (float) Math.random();
                }
            }
            start = System.currentTimeMillis();
            multiplicate(matrixA, matrixB);
            elapsedTime = ((double)(System.currentTimeMillis() - start))/1000;
            System.out.println("Dim = " + n + " Time: " + elapsedTime + " s");
        }
    }

}
