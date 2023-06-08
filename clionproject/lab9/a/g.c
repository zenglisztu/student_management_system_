#include <stdio.h>
#include <stdlib.h>
#define N 100

int input_team(int arr[]);
int mach(int arr[], int size_t);
int main(int argc, char *argv[])
{
    int team[N] = {-9};
    int len = 0;
    int i = 0;
    len = input_team(team);
    for(i = 0; i < len/2; i++)
    {
        mach(team, len);
    }

    system("pause");
    return 0;
}

int input_team(int arr[])
{
    char ch_m = 0;
    char ch = 0;
    int i = 0;
    ch_m = getchar();
    arr[i] = 1;
    i++;
    while(~scanf("%c", &ch))
    {
        if(ch == ch_m)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = -1;
        }
        i++;
    }
    return i;
}

int mach(int arr[], int size_t)
{
    int i = 0;
    int j = 1;
    for(i = 0; i < size_t - 1; i++, j++)
    {
        while(arr[j] == -10)
        {
            j++;
        }
        while(arr[i] == -10)
        {
            i++;
        }
        if((arr[i] + arr[j] == 0)&&(arr[i] > arr[j]))
        {
            printf("%d %d\n" ,i, j);
            arr[i] = -10;
            arr[j] = -10;
            break;
        }
    }
    return 0;
}