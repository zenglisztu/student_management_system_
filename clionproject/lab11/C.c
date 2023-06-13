//
// Created by 曾立 on 2023/6/13.
//
#include <stdio.h>
#include <string.h>
#define MAXN 10
int ArrayShift( int a[], int n, int m );
int main()
{
    int a[MAXN], n, m;
    int i;
    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);
    ArrayShift(a, n, m);
    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}

int ArrayShift( int a[], int n, int m )
{
    int i = 0;
    int j = 0;
    int tmp[n];
    memset(tmp, 0, n * sizeof(int));

    m %= n;

    for (i = n - m; i < n; i++)
    {
        tmp[j] = a[i];
        j++;
    }
    for (i = 0; i < n - m; i++)
    {
        tmp[j] = a[i];
        j++;
    }
    memcpy(a, tmp, n * sizeof(int));

    return 0;
}