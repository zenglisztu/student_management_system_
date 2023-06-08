//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#define N 80
//
//int is_0x(char ch);
//int get_hex(char str[]);
//int change_hex(char str[], int size_t);
//int main(int argc, char *argv[])
//{
//    char hex_ch[N] = {0};
//    int len = 0;
//    len = get_hex(hex_ch);
//    //printf(hex_ch);
//    printf("%d\n",change_hex(hex_ch, len));
//    system("pause");
//    return 0;
//}
//int get_hex(char str[])
//{
//    char ch = 0;
//    int i = 0;
//    while((ch = getchar()) != '#')
//    {
//        if(ch == '-' && i == 0)
//        {
//            str[i] = ch;
//            i++;
//        }
//        if(is_0x(ch))
//        {
//            str[i] = ch;
//            i++;
//        }
//    }
//    return i;
//}
//
//int is_0x(char ch)
//{
//    if((ch >= '0' && ch <= '9') ||(ch >= 'A' && ch <= 'F')||(ch >= 'a' && ch <= 'f'))
//    {
//        return 1;
//    }
//    return 0;
//}
//
//int change_hex(char str[], int size_t)
//{
//    int sum = 0;
//    int i = size_t;
//    int j = 0;
//    if(str == NULL || size_t <=0)
//    {
//        printf("parameter invalid");
//        return -1;
//    }
//    for(i = size_t - 1; i >= 0; i--)
//    {
//        if(str[i] == '-')
//        {
//            sum *= -1;
//            continue;
//        }
//        if(str[i] >= '0'&& str[i] <= '9')
//        {
//            sum += pow(16,j) * (int)(str[i] - '0');
//        }
//        else if(str[i] >= 'A'&& str[i] <= 'F')
//        {
//            sum += pow(16,j) * (int)(10 + str[i] - 'A');
//        }
//        else if(str[i] >= 'a'&& str[i] <= 'f')
//        {
//            sum += pow(16,j) * (int)(10 + str[i] - 'a');
//        }
//        j++;
//
//    }
//    return sum;
//
//}