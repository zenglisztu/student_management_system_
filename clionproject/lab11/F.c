//
// Created by 曾立 on 2023/6/13.
//
#include <stdio.h>
#include <string.h>
#define N 80

int main(int argc, char *argv[])
{
    char max_str[N] = "";
    char str[N] = {0};
    int n = 0;

    scanf("%d", &n);

    while (n)
    {
        scanf("%s", str);

        if (strlen(str) > strlen(max_str))
        {
            strcpy(max_str, str);
        }
        n--;
    }
    printf("The longest is: %s", max_str);
    return 0;
}