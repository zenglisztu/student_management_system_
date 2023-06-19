//
// Created by ÔøÁ¢ on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    void ShowClassName()
    {
        cout << "The class name is Person" << endl;
    }

    void PrintAge()
    {
        if (this == nullptr)
        {
            return;
        }
        cout << name_ << "'s age is " << endl;
    }

    void PrintName()
    {
        if (this == nullptr)
        {
            return;
        }
        cout << "name is " << name_ << endl;
    }

    string name_;
    int age_;

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
    Person *p = nullptr;

    p->ShowClassName();
    p->PrintAge();
    p->PrintName();
}