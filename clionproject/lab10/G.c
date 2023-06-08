//
// Created by 曾立 on 2023/6/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **creat_2darr(int row, int col);
int free_2darr(int **arr, int row, int col);
void print_arr(int **arr, int row, int col);
int ** creat_screw_arr(int **arr, int row, int col);
int main(int argc, char *argv[])
{
    int ** _2darr = NULL;
    int row = 0;
    int col = 0;
    scanf("%d", &row);
    scanf("%d", &col);
    _2darr = creat_2darr(row, col);
    print_arr(creat_screw_arr(_2darr, row, col), row, col);
    free_2darr(_2darr, row, col);

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
        if(col == 1)
        {
            break;
        }
    }
    free(arr);
    arr = NULL;
    return 0;
}

int ** creat_screw_arr(int **arr, int row, int col)
{
    int i = 0;
    int j = 0;
    int num = 1;
    //控制圈数
    for(i = 0; i < row/2 + 1; i++)
    {
        //向左
        for(j = col - i - 1; j >= 1 + i; j--)
        {
            arr[i][j] = num++;
        }
        //向下
        for(j = 0 + i; j < row -1 - i; j++)
        {
            arr[j][i] = num++;
        }
        //向右
        for(j = 0 + i; j < col - 1 - i; j++)
        {
            arr[row - i - 1][j] = num++;
        }
        //向上
        for(j = row - 1 - i; j >= 1 + i; j--)
        {
            arr[j][col - 1 - i]= num++;
        }

    }
    if(row == col && row%2 != 0)
    {
        arr[row/2][col/2] = row*col;
    }
    return arr;
}

void print_arr(int **arr, int row, int col)
{
    int i = 0;
    int j = 0;
    if( row == 1)
    {
        for(i = col; i >= 1; i--)
        {
            printf("%6d",i);
        }
        return;
    }
    if(col == 1)
    {
        for(i = 1; i <= row; i++)
        {
            printf("%6d\n", i);
        }
        return;
    }
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%6d",arr[i][j]);
        }
        printf("\n");
    }
}

