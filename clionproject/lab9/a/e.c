//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#define N 32
//
//int input_ip(int* p, int size_t);
//void print_ip(int arr[], int size_t);
//int main(int argc, char *argv[])
//{
//    int ip[N] = {0};
//    input_ip(ip, N);
//    print_ip(ip, N);
//
//    system("pause");
//    return 0;
//}
//
//int input_ip(int* p, int size_t)
//{
//    int i = 0;
//    for (i = 0; i < size_t; i++)
//    {
//        scanf("%1d", p + i);
//    }
//    return 0;
//}
//
//void print_ip(int arr[], int size_t)
//{
//    int i = 0;
//    int j = 7;
//    int ip_section = 0;
//    for(i = 0; i< size_t; i++)
//    {
//        ip_section += pow(2, j)*arr[i];
//        if((i + 1)%8 == 0)
//        {
//           printf("%d",ip_section);
//           if(i != size_t -1)
//           {
//               printf(".");
//           }
//           ip_section = 0;
//           j = 7;
//           continue;
//        }
//        j--;
//    }
//}