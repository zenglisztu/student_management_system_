//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
//    Person operator+(const Person& p)
//    {
//        Person temp;
//        temp.age_ = this->age_ + p.age_;
//        temp.score_ = this->score_ + p.score_;
//
//        return temp;
//    }
    int score_;
    int age_;
};

Person operator+(const Person& p1, const Person& p2)
{
    Person temp;
    temp.age_ = p1.age_ + p2.age_;
    temp.score_ = p1.score_ + p2.score_;

    return temp;
}

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
    Person p2;
    p1.age_ = 18;
    p2.age_ = 23;
    p1.score_ = 100;
    p2.score_ = 100;
    Person p3 = p1 + p2;

    cout << "p3's age is " << p3.age_ << endl;
    cout << "p3's score is " << p3.score_ << endl;
}