#include <stdio.h>

#define ROWS 5
#define COLS 5

void fillSpiral(int arr[ROWS][COLS], int result[], int n) {
    int row_start = 0, row_end = ROWS - 1;
    int col_start = 0, col_end = COLS - 1;
    int index = 0;

    while (row_start <= row_end && col_start <= col_end) {
        // Вправо
        for (int i = col_start; i <= col_end; i++) {
            result[index++] = arr[row_start][i];
        }
        row_start++;

        // Вниз
        for (int i = row_start; i <= row_end; i++) {
            result[index++] = arr[i][col_end];
        }
        col_end--;

        // Влево
        if (row_start <= row_end) {
            for (int i = col_end; i >= col_start; i--) {
                result[index++] = arr[row_end][i];
            }
            row_end--;
        }

        // Вверх
        if (col_start <= col_end) {
            for (int i = row_end; i >= row_start; i--) {
                result[index++] = arr[i][col_start];
            }
            col_start++;
        }
    }
}

int main() {
    int twoDimArray[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int n = ROWS * COLS;
    int result[n];

    fillSpiral(twoDimArray, result, n);

    printf("Одномерный массив, заполненный спирально:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
