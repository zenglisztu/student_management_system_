//
// Created by 曾立 on 2023/6/23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Test01();
void PrintInt(int value);
int main(int argc, char *argv[])
{

    Test01();

    system("pause");
    return 0;
}

void Test01()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int>::iterator itr_start = v1.begin();
    vector<int>::iterator itr_end = v1.end();

    while (itr_start != itr_end)
    {
        cout << *itr_start << endl;
        itr_start++;
    }

    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << endl;
    }
    for_each(v1.begin(), v1.end(), PrintInt);

    for (const auto& value : v1)
    {
        cout << value << endl;
    }
}

void PrintInt(int value)
{
    cout << value << endl;
}