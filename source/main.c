#include <stdio.h>
#include <stdlib.h>

#include "../headers/matrix_actions.h"

int main()
{
    int m, n;
    float **matrix;
    enum Errors error;
    int stop_flag = 1;

    printf("Введите количество строк и столбцов: ");
    scanf("%d %d", &m, &n);

    error = matrix_init(&matrix, m, n);
    if (error != MRX_OK) {
        printf("matrix_init_error\n");
        return error;
    }
    error = matrix_input(matrix, m, n);
    if (error != MRX_OK) {
        printf("Wrong input restart the programm\n");
        return error;
    }

    matrix_print(matrix, m, n);
    printf("_________________________________________________________\n");

    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            if (matrix[j][0] != 0) {
                printf("Поменяем местами %d и %d cтроки\n", 0, j);
                string_trade(matrix[j], matrix[0], n);
                break;
            }
        }
    }

    for (int i = 0; (i < m) && (i < n); i++) {
        if (matrix[i][i] == 0) {
            for (int j = i + 1; j < m; j++) {
                if (matrix[j][i] != 0) {
                    printf("Поменяем местами %d и %d cтроки\n", i, j);
                    string_trade(matrix[j], matrix[i], n);
                    stop_flag = 0;
                    break;
                }
            }
            if(stop_flag) {
                break;
            }
        }
        printf("Разделим строку %d на ведущий элемент\n", i);
        string_mul(matrix[i], 1.0f/matrix[i][i], n);
        for (int j = 0; j < m; j++) {
            if(matrix[j][i] == 0 || j == i)
                continue;
            printf("Прибавим к строке %d строку %d умноженную на %4.3f\n", j, i, -matrix[j][i]);
            string_sum(matrix[j], matrix[i], -matrix[j][i], n);
            

        }
        matrix_print(matrix, m, n);
        printf("_________________________________________________________\n");
    }
    for (int j = 0; j < m; j++) {
        if (string_is_zero(matrix[j], n - 1) && matrix[j][n - 1] != 0) {
            printf("Матрица не имеет решения\n");
        }
    }
    free(matrix);
}
