//
// Created by 曾立 on 2023/6/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **creat_2darr(int row, int col);
int free_2darr(int **arr, int row, int col);
int **creat_yht(int **arr, int row);
void print_yht(int **arr, int row);
void print_blank(int size_b);
int main(int argc, char *argv[])
{
    int ** _2darr = NULL;
    int row = 0;
    scanf("%d", &row);
    _2darr = creat_2darr(row, row);
    print_yht(creat_yht(_2darr, row), row);
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

int **creat_yht(int **arr, int row)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(0 == j || j == i)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
        }
    }
    return arr;
}

void print_yht(int **arr, int row)
{
    int i = 0;
    int j = 0;
    int blank = row - 1;
    for(i = 0; i < row; i++)
    {
        print_blank(blank);
        for(j = 0; j <= i; j++)
        {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
        blank--;
    }
}

void print_blank(int size_b)
{
    int i = 0;
    for(i = 0; i< size_b; i++)
    {
        putchar(' ');
    }
}

