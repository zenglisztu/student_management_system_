//
// Created by 曾立 on 2023/6/13.
//
#include <stdio.h>
#include <string.h>
#define MAXN 20

void delchar( char *str, char c );
void ReadString( char s[]){
    gets(s);
}
int main()
{
    char str[MAXN], c;

    scanf("%c\n", &c);
    ReadString(str);
    delchar(str, c);
    printf("%s\n", str);

    return 0;
}

void delchar( char *str, char c )
{
    char tmp[MAXN] = {0};
    int i = 0;
    int j = 0;

    for(i = 0; i < strlen(str); ++i)
    {
        if (str[i] != c)
        {
            tmp[j] =str[i];
            j++;
        }
    }
    strcpy(str, tmp);

}