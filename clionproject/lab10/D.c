//
// Created by 曾立 on 2023/6/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **creat_2darr(int row, int col);
int free_2darr(int **arr, int row, int col);
int **input_2darr(int **arr, int row, int col);
int is_utm(int **arr, int row, int col);
int main(int argc, char *argv[])
{
    int ** _2darr = NULL;
    int n = 0;
    int row = 0;
    int col = 0;
    scanf("%d", &n);
    while(n)
    {
        scanf("%d", &row);
//    scanf("%d", &col);
        col = row;
        _2darr = creat_2darr(row, col);
        input_2darr(_2darr, row, col);
        if(is_utm(_2darr, row, col))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        n--;
    }
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

int is_utm(int **arr, int row, int col)
{
    int i = 0;
    int j = 0;
    int flag = 1;
    for(i = 0; i < col -1; i++)
    {

        for(j = flag; j < row; j++)
        {
            if(arr[j][i] != 0)
            {
                return 0;
            }
        }
        flag++;
    }
    return 1;
}