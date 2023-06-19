//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    static void stat_func()
    {
        score = 100;
        cout << "静态函数的调用" << endl;
        cout << "score: " << score << endl;
    }

    static int score;

};

int Person:: score = 0;

void Test01();

int main(int argc, char *argv[])
{

    Test01();

    system("pause");
    return 0;
}

void Test01()
{
    Person::stat_func();
}

