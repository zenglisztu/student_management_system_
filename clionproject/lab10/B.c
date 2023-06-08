//
// Created by 曾立 on 2023/6/6.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **creat_2darr(int row, int col);
int free_2darr(int **arr, int row, int col);
int **input_2darr(int **arr, int row, int col);
int print_row_sum(int **arr, int row, int col);
int main(int argc, char *argv[])
{
    int ** _2darr = NULL;
    int row = 0;
    int col = 0;
    scanf("%d", &row);
    scanf("%d", &col);
    _2darr = creat_2darr(row, col);
    input_2darr(_2darr, row, col);
    print_row_sum(_2darr, row, col);
    return 0;
}

int **creat_2darr(int row, int col)
{
    int **arr = NULL;
    int i = 0;
    arr = (int **)malloc(row * sizeof(int*));
    for(i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
        memset(arr[i], 0, col * sizeof(int));
    }
    return arr;
}
int free_2darr(int **arr, int row, int col)
{
    int i = 0;
    for(i = 0; i < row; i++)
    {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
    return 0;
}

int **input_2darr(int **arr, int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    return arr;
}

int print_row_sum(int **arr, int row, int col)
{
    int sum = 0;
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        printf("%d\n", sum);
        sum = 0;
    }
    free_2darr(arr, row, col);

    return 0;
}