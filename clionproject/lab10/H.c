//
// Created by 曾立 on 2023/6/7.
//
//
// Created by 曾立 on 2023/6/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **creat_2darr(int row, int col);
int free_2darr(int **arr, int row, int col);
void print_arr(int **arr, int row, int col);
int ** creat_spin_arr(int **arr, int row, int col, int size_n);
int main(int argc, char *argv[])
{
    int ** _2darr = NULL;
    int num = 0;
    int row = 0;
    int col = 5;
    scanf("%d", &num);
    scanf("%d", &row);
    _2darr = creat_2darr(row, col);
    print_arr(creat_spin_arr(_2darr, row, col, num), row, col);
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
        memset(arr[i], -1, col * sizeof(int));
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

int ** creat_spin_arr(int **arr, int row, int col, int size_n)
{
    int i = 0;
    int j = 0;
    int num = 1;
    //控制圈数
    for(i = 0; i < row; i += 2)
    {
        //向右
        for(j = 0 ; j < col; j++)
        {
            arr[i][j] = num++;
            if(num > size_n)
            {
                return arr;
            }
        }
        //向左
        for(j = col - 1; j >= 0; j--)
        {
            arr[i + 1][j] = num++;
            if(num > size_n)
            {
                return arr;
            }
        }

    }
    return arr;
}

void print_arr(int **arr, int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%5d",arr[i][j]);
        }
        printf("\n");
    }
}

