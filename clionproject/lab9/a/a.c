//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define N 100
//
//int count_f(const char str_[]);
//int is_upper(const char ch);
//int is_f(const char ch);
//int main(int argc, char *argv[])
//{
//    char str[N] = {0};
//    gets(str);
//
//    printf("%d\n", count_f(str));
//
//    system("pause");
//    return 0;
//}
//
//int count_f(const char str_[])
//{
//    int res = 0;
//    int len = strlen(str_);
//    int i = 0;
//    for(i = 0; i < len; i++)
//    {
//        if(is_upper(str_[i])&&is_f(str_[i]))
//        {
//            res++;
//        }
//    }
//
//    return res;
//}
//
//int is_upper(const char ch)
//{
//    if(ch >= 'A' && ch <= 'Z')
//    {
//        return 1;
//    }
//
//    return 0;
//}
//
//int is_f(const char ch)
//{
//    char y[] = {'A', 'E', 'I', 'O', 'U'};
//    int i = 0;
//    for(i = 0; i < 5; i++)
//    {
//        if(ch == y[i])
//        {
//            return 0;
//        }
//
//    }
//    return 1;
//}