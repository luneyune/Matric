#include <stdio.h>
#include <stdlib.h>

#include "../headers/matrix_actions.h"

/* matrix_init создает матрицу m на n по адресу matrix
*/
int matrix_init(float*** matrix, int m, int n)
{
    *matrix = (float**)malloc(m*sizeof(float*) + m*n*sizeof(float));
    if(NULL == *matrix) return MRX_MALLOC_ERR;

    float* start = (float*)((void*)(*matrix) + m*sizeof(float*));

    for (int i = 0; i < m; i++) {
        (*matrix)[i] = start + i*n;
    }
    return MRX_OK;
}

// matrix_input запрашивает у пользователя числа и записыват их в матрицу
int matrix_input(float** matrix, int m, int n)
{
    for (int i = 0; i < m; i++) {
        printf("Введите %d строку матрицы\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            if (scanf("%f", &matrix[i][j]) != 1) return MRX_INPUT_ERR;
        }
        printf("\n");
    }
    
    return MRX_OK; 
}

// matrix_printf распечатывает матрицу
void matrix_print(float** matrix, int m, int n)
{
    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("( ");
        for (int j = 0; j < n - 1; j++) {
            printf("%4.1f ", matrix[i][j]);
        }
        printf("| %4.1f )\n", matrix[i][n - 1]);
    }
}

// string_is_zero проверяет заполнена ли строка вся нулями
int string_is_zero(float* a, int len)
{
    for (int i = 0; i < len; i++) {
        if (a[i] != 0) return 0;
    }
    return 1;
}

/* string_sum кладет в а поэлементную сумму а и b*k
*/
int string_sum(float* a, const float* b, float k, int len)
{
    for (int i = 0; i < len; i++) {
        a[i] += b[i]*k;
    }
    return MRX_OK;
}

/* string_mul умножает каждый элемент а на k и кладет
результат вычисления в a
*/
int string_mul(float* a, float k, int len)
{
    for (int i = 0; i < len; i++) {
        a[i] *= k;
    }
    return MRX_OK;
}

// string_trade меняет строки местами
int string_trade(float* a, float* b, int len)
{
    float tmp;
    for (int i = 0; i < len; i++) {
        tmp = b[i];
        b[i] = a[i];
        a[i] = tmp;
    }
    return MRX_OK;

}