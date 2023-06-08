//
// Created by 曾立 on 2023/6/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **creat_2darr(int row, int col);
int free_2darr(int **arr, int row, int col);
int **input_2darr(int **arr, int row, int col);
void print_r_move(int **arr, int row, int step);
void print_arr(int **arr, int row, int col);
int main(int argc, char *argv[])
{
    int ** _2darr = NULL;
    int step = 0;
    int row = 0;
    scanf("%d", &step);
    scanf("%d", &row);

    _2darr = creat_2darr(row, row);
    input_2darr(_2darr, row, row);
    print_r_move(_2darr, row, step);
    free_2darr(_2darr, row, row);

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

void print_r_move(int **arr, int row, int step)
{
    int i = 0;
    int j = 0;
    int k = 0;
    step = (step)%row;
    if(step == 0)
    {
        print_arr(arr, row, row);
        return;
    }
    for(i = 0; i < row; i++ )
    {
        for(j = row - step; j < row; j++)
        {
            printf("%d ", arr[i][j]);
        }
        for(k = 0; k < row - step; k++)
        {
            printf("%d ", arr[i][k]);
        }
        printf("\n");
    }

}

void print_arr(int **arr, int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
