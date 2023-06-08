#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 80

double split(char str[]);
void print_section(char str[N][10],int row);
int main(int argc, char *argv[])
{
    char str[N] = {0};
    int times = 0;
    int i = 0;
    scanf_s("%d", &times);
    while(getchar() != '\n')
    {

    }
    for(i = 0; i < times; i++)
    {
        gets(str);
        printf("%.2lf\n", split(str));
    }


    system("pause");
    return 0;
}

double split(char str[])
{
    char used_str[N][10] = {0};
    char *p = NULL;
    int i = 0;
    int col = 0;
    int row = 0;
    p = str + 1;
    for(i = 0; i < strlen(str); i++)
    {
        used_str[row][col] = str[i];
        col++;
        if(*(p+i) != str[i])
        {
            row++;
            col = 0;
        }
    }
    print_section(used_str, row);
    return strlen(str)/(double)row;
}

void print_section(char str[N][10],int row)
{
    char str_used[N][10] = {0};
    int i = 0;
    int j = 0;
    int flag = 1;
    int row_u = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0;j < i ;j++)
        {
            flag = strcmp(str[i],str_used[j]);
            if(!flag)
            {
                break;
            }
        }
        if(flag)
        {
            printf(str[i]);
            printf(" ");
            strcpy(str_used[row_u],str[i]);
            row_u++;
        }

    }
}