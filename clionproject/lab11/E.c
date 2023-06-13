//
// Created by 曾立 on 2023/6/13.
//
#include <stdio.h>
#include <string.h>
#define N 80

int main(int argc, char *argv[])
{
    char min_str[N] = "z";
    char str[N] = {0};
    int n = 0;

    scanf("%d", &n);

    while (n)
    {
        scanf("%s", str);

        if (strcmp(str, min_str) < 0)
        {
            strcpy(min_str, str);
        }
        n--;
    }
    printf("Min is: %s", min_str);
    return 0;
}