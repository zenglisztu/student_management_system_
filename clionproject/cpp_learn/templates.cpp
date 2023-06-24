//
// Created by 曾立 on 2023/6/23.
//
#include <iostream>
#include <string>

using namespace std;

template<typename T>
T add(const T& value1, const T& value2);
void Test01();
void Test02();
int main(int argc, char *argv[])
{
    Test01();
    Test02();
    system("pause");
    return 0;
}

template<typename T>
T add(const T& value1, const T& value2)
{
    return value1 + value2;
}

void Test01()
{
    int a = 10;
    int b = 10;
    cout << add<int>(a, b) << endl;
}

void Test02()
{
    double a = 1.1;
    double b = 1.2;
    cout << add(a, b) << endl;
}