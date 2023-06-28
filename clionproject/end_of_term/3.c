/*
 * 输入4个字符（数字或字母），设'a'对应序号1，'b'对应序号2，···，
 * 'z'对应序号26，'A'对应序号-1，'B'对应序号-2，···，'Z'对应序号-26，
 * 现规定校验码为所有字母或数字的序号之和，把它放在最后。
   例如输入：a1B7     输出：a1B77

 */
#include <stdio.h>
#define N 10

int ChangeChar(char ch);

int main(int argc, char *argv[])
{
    char str[N] = {0};
    int end_num = 0;
    int i = 0;

    gets(str);

    for (i = 0; str[i] != '\0'; i++)
    {
        end_num += ChangeChar(str[i]);
    }

    printf("%s%d\n", str, end_num);
    return 0;
}

int ChangeChar(char ch)
{
    int res = 0;
    if (ch >= 'A' && ch <= 'Z')
    {
        res = -(ch - 'A' + 1);
    }
    else if ( ch >= 'a' && ch <= 'z')
    {
        res = (ch - 'a' + 1);
    }
    else if( ch >= '0' && ch <= '9')
    {
        res = ch - '0';
    }

    return res;
}