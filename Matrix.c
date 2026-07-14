#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int sum[MAX][MAX],
               int rows, int cols);
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int product[MAX][MAX],
                    int r1, int c1, int c2);
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX],
                     int rows, int cols);

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter elements of first matrix:\n");
    inputMatrix(a, r1, c1);

    printf("\n1. Addition\n2. Multiplication\n3. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter rows and columns of second matrix: ");
            scanf("%d %d", &r2, &c2);

            if (r1 != r2 || c1 != c2) {
                printf("Addition is not possible.\n");
                break;
            }

            printf("Enter elements of second matrix:\n");
            inputMatrix(b, r2, c2);

            addMatrix(a, b, result, r1, c1);
            printf("Sum of matrices:\n");
            displayMatrix(result, r1, c1);
            break;

        case 2:
            printf("Enter rows and columns of second matrix: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("Multiplication is not possible.\n");
                break;
            }

            printf("Enter elements of second matrix:\n");
            inputMatrix(b, r2, c2);

            multiplyMatrix(a, b, result, r1, c1, c2);
            printf("Product of matrices:\n");
            displayMatrix(result, r1, c2);
            break;

        case 3:
            transposeMatrix(a, result, r1, c1);
            printf("Transpose of first matrix:\n");
            displayMatrix(result, c1, r1);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int sum[MAX][MAX],
               int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int product[MAX][MAX],
                    int r1, int c1, int c2) {
    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            product[i][j] = 0;

            for (k = 0; k < c1; k++) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX],
                     int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}