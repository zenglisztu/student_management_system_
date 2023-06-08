//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define N 80
//
//int input_password(int* p, int size_t, int *len);
//int print_new_password(int password[], int seed, int size_t);
//int main(int argc, char *argv[])
//{
//    int password[N] = {0};
//    int seed = 0;
//    int len = 0;
//    seed = input_password(password, N, &len);
//    print_new_password(password, seed, len);
//    system("pause");
//    return 0;
//}
//
//int input_password(int* p, int size_t, int *len)
//{
//    int i = 0;
//    char ch[N] = {0};
//    int sum = 0;
//    gets(ch);
//    *len = strlen(ch);
//    for (i = 0; i < strlen(ch); i++)
//    {
//        *(p + i) = (int)(ch[i] - '0');
//        sum += *(p+i);
//    }
//    return (int)sum%10;
//}
//
//int print_new_password(int password[], int seed, int size_t)
//{
//    int i = 0;
//    for(i = 0; i < size_t; i++)
//    {
//        printf("%d", (int)((password[i] + seed)%10));
//    }
//    return 0;
//}