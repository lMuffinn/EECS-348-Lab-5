#include <stdio.h>

#define SIZE 5

int *addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]){
    int newM[SIZE][SIZE];
    for (int i = 0; i<SIZE; i++){
        for (int j = 0; j<SIZE; j++){
            newM[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return *newM;
}

void printMatrix(int **m){
    for (int i = 0; i<SIZE; i++){
        for (int j = 0; j<SIZE; j++){
            printf("%d, ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    printMatrix(*addMatrices(m1,m2));
    char exit;
    printf("Press enter to exit:");
    scanf("%c",&exit);
}
