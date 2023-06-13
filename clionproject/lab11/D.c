//
// Created by 曾立 on 2023/6/13.
//
#include <stdio.h>
#include <stdlib.h>

double max_score(const int *arr, int size_n);
double min_score(const int *arr, int size_n);
double average_score(const int *arr, int size_n);

int main(int argc, char *argv[])
{
    int i = 0;
    int size_n = 0;
    int *pint = NULL;

    scanf("%d", &size_n);

    pint = (int *)malloc(size_n * sizeof(int));

    for (i = 0; i < size_n; ++i)
    {
        scanf("%d", &pint[i]);
    }

    printf("average = %.2lf\n", average_score(pint, size_n));
    printf("max = %.2lf\n", max_score(pint, size_n));
    printf("min = %.2lf\n", min_score(pint, size_n));


    return 0;
}

double max_score(const int *arr, int size_n)
{
    int max = 0;
    int i = 0;

    for (i = 1; i < size_n; ++i)
    {
        if(arr[i] > arr[max])
        {
            max = i;
        }
    }

    return (double)arr[max];
}

double min_score(const int *arr, int size_n)
{
    int min = 0;
    int i = 0;

    for (i = 1; i < size_n; ++i)
    {
        if(arr[i] < arr[min])
        {
            min = i;
        }
    }

    return (double)arr[min];
}

double average_score(const int *arr, int size_n)
{
    int sum_score = 0;
    int i = 0;

    for (i = 0; i < size_n; ++i)
    {
        sum_score += arr[i];
    }

    return (double)sum_score / size_n;
}