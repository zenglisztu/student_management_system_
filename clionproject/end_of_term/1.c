/*
 * 输入4个整数，计算并输出这些整数的和与平均值，
 * 平均值要求精确到小数点后2位。
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int sum = 0;
    int number = 0;
    int n = 4; //控制读入整数的次数

    while(n)
    {
        scanf("%d", &number);
        sum += number;
        n--;
    }

    printf("%.2f\n", (double)sum / 4);
    return 0;
}
