//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace  std;

class Person
{
public:

    Person(string&& name, int age):
    name_(std::move(name)),
    age_(age){}

    string name_;
    int age_;

    Person& AgeAdd(const Person& p)
    {
        this->age_ += p.age_;
        return *this;
    }

};

void Test01();
int main(int argc, char *argv[])
{

    Test01();

    system("pause");
    return 0;
}

void Test01()
{
    Person p1("xia li", 18);
    Person p2("xio z", 23);

    p2.AgeAdd(p1).AgeAdd(p1);
    cout << "p1's name is " << p1.name_ << endl;
    cout << p2.name_ << " age is " << p2.age_ << endl;

}

