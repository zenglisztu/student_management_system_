/*
 * 杂乱地输入一串数字，可能会有重复，把这些数字按照顺序排序，只对0，1，2，3，4排序，别的数字按原样输出。
 * 例如输入：4 9 8 3 7 2 0 4 8
    输出： 9 8 7 8 0 2 3 4 4

 */

#include <stdio.h>
#define N 20

int GetNum( int int_arr[]);
int SplitArr(int src[], int sta[], int sort[], int size);
void SortArr(int arr[], int size);
void PrintArr(int arr[], int size);

int main(int argc, char *argv[])
{
    int num_arr[N] = {0}; //用于存储读入的所有数字
    int sta[N] = {0};  //用于储存不需要排序的数字
    int sort[N] = {0}; //用于储存需要排序的数字
    int num_amount = 0; //读入数字的个数
    int sort_amount = 0; //需要排序的数字个数

    num_amount  = GetNum(num_arr); //读入数字
    sort_amount = SplitArr(num_arr, sta, sort, num_amount); //将储存所有数字的数组拆分
    SortArr(sort, sort_amount); //对需要排序的数组进行排序

    PrintArr(sta, num_amount - sort_amount); //打印无需排序的数组
    PrintArr(sort, sort_amount); //打印排序后的数组
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

int SplitArr(int src[], int sta[], int sort[], int size)
{
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < size; i++)
    {
        if (src[i] == 0 || src[i] == 1 || src[i] == 2 || src[i] == 3 || src[i] == 4)
        {
            sort[j] = src[i];
            j++;
        }
        else
        {
            sta[k] = src[i];
            k++;
        }
    }

    return j;
}

void SortArr(int arr[], int size)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < size; i ++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }
}

void PrintArr(int arr[], int size)
{
    int i = 0;

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}