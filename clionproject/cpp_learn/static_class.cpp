//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:

    static int score;

};

int Person::score = 100;

void Test01();

int main(int argc, char *argv[])
{
    Test01();

    system("pause");
    return 0;
}

void Test01()
{
    Person p1;
    cout << Person::score << endl;
    p1.score = 200;
    cout << Person::score << endl;
}