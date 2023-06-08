//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define N 80
//
//int is_upper(char ch);
//char change(char ch);
//int main(int argc, char *argv[])
//{
//    char str[N] = {0};
//    int i = 0;
//    gets(str);
//    for(i = 0; i < strlen(str);i++)
//    {
//        if(is_upper(str[i]))
//        {
//            str[i] = change(str[i]);
//        }
//    }
//    printf(str);
//    system("pause");
//    return 0;
//}
//
//char change(char ch)
//{
//    return (char)('A' + 'Z' - ch);
//}
//
//int is_upper(char ch)
//{
//    if(ch >= 'A' && ch <= 'Z')
//    {
//        return 1;
//    }
//
//    return 0;
//}