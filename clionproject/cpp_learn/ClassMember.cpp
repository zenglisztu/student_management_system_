//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Phone
{
public:
    Phone(const string& name, int price):PName(name), PPrice(price)
    {

    }

    string PName;
    int PPrice;
};

class Person
{
public:
    Person(const string& name, int age, const string& p_name, int p_price):name(name), age(age), phone(p_name, p_price)
    {

    }

    string name;
    int age;
    Phone phone;

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
    Person p("xioali", 18, "apple", 10000);
    cout << "p's name is " << p.name << endl;
    cout << "p's age is " << p.age << endl;
    cout << "p's phone brand is " << p.phone.PName << endl;
    cout << "p's phone price is " << p.phone.PPrice << endl;
}