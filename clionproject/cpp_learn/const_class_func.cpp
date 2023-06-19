//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person()
    {

    }
    void PrintClass() const
    {
        cout << "The class is Person" << endl;
        //age_ = 100;
        score_ = 100;
    }

    int age_;
    mutable int score_;

};

void Text01();
int main(int argc, char *argv[])
{

    Text01();

    system("pause");
    return 0;
}

void Text01()
{
    const Person p;
    p.PrintClass();
    p.score_ = 100;
    //p.age_ = 20;

}