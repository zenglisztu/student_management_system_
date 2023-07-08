#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Tag
{
    int num;
    double num2;
};
int main(int argc, char *argv[])
{

    union Tag u1 = {0};
    u1.num2 = 2.2;
    unsigned int x = 0x12345678;
    unsigned char *p = (unsigned char *)&x;

    printf("%p = 0x%x\n", p, *p);
    printf("%p = 0x%x\n", p + 1, *(p + 1));
    printf("%p = 0x%x\n", p + 2, *(p + 2));
    printf("%p = 0x%x\n", p + 3, *(p + 3));

    printf("%zd\n", sizeof(union Tag));
    printf("%f\n", u1.num2);
    system("pause");
    return 0;
}
