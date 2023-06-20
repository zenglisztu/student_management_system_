//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:

    explicit Person(int age)
    {
        age_ = new int(age);
    }

    int GetAge()
    {
        return *age_;
    }

    ~Person()
    {
        if (age_ != nullptr)
        {
            delete age_;
            age_ = nullptr;
        }
    }
    Person& operator=(const Person& p)
    {
        if (&p == this)
        {
            return *this;
        }

        if (p.age_ == nullptr)
        {
            return *this;
        }

        if (this->age_ != nullptr)
        {
            delete age_;
            age_ = nullptr;
        }

        age_ = new int(*(p.age_));

        return *this;
    }
private:
    int *age_;
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
    Person p1(18);
    Person p2(20);
    Person p3(100);
    p3 = p2 = p1;
    cout << p1.GetAge() << endl;
    cout << p2.GetAge() << endl;
    cout << p3.GetAge() << endl;
}