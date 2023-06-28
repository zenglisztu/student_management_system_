//
// 本题要求编写程序，输出给定正整数M和N区间内的所有三位水仙花数。三位水仙花数，
// 即其个位、十位、百位数字的立方和等于该数本身。输入在一行中给出两个正整数M和N（100≤M≤N≤999）。
//
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int M = 0;
    int N = 0;
    int i  = 0;

    scanf("%d", &M);
    scanf("%d", &N);

    for (i = M; i <=N; i++)
    {
        if(pow(i % 10, 3) + pow((i / 10) % 10, 3) + pow(i / 100, 3) == i)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}