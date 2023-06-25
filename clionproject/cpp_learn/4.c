//
// Created by 曾立 on 2023/6/25.
//
#include <stdio.h>
#include <stdlib.h>
#define N 20

int GetNum( int int_arr[]);
int SearchMostNumIndex(int *arr, int size);

int main(int argc, char *argv[])
{
    int arr[N] = {0};
    int num_amount;

    //读入数据
    num_amount = GetNum(arr);
    //找到出现最多次数数字下标并打印
    printf("%d\n", SearchMostNumIndex(arr, num_amount));

    system("pause");
    return 0;
}

/// 从命令行读取数字保存到数组中
/// \param int_arr 用于存储读取数字的数组
/// \return 返回值为读入数字的个数
int GetNum( int int_arr[])
{
    char ch = 0;
    int i = 0;

    //以字符类型读入数字
    scanf("%c", &ch);
    while (ch != '\n')
    {
        //去除空格
        if (ch != ' ')
        {
            //将读入的字符转换为对应整型值储存到数组中
            int_arr[i] = (int)ch - (int)'0';
            i++;
        }

        scanf("%c", &ch);
    }
    //返回数组中有效元素个数
    return i;
}


int SearchMostNumIndex(int *arr, int size)
{
    int count = 0;
    int max_count = 1;
    int index = -1;
    int i = 0;
    int j = 0;

    for (i = 0; i < size ; i++)
    {
        count = 0;
        for (j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count >= max_count)
        {
            max_count = count;
            index = i + 1; //因为数组下标是从0开始而且题目位置从1开始，所以下标需加1
        }
    }

    return index;
}