//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class MyInt
{
    friend ostream& operator<<(ostream& c_out, MyInt my_int);
public:
    MyInt& operator++()
    {
        int_++;
        return *this;
    }
    MyInt operator++(int)
    {
        MyInt temp = *this;
        ++(*this);
        return temp;
    }
    MyInt()
    {
        int_ = 0;
    }

private:
    int int_;
};

ostream& operator<<(ostream& c_out, MyInt my_int);
void Test01();
void Test02();

int main(int argc, char *argv[])
{
    Test02();

    system("pause");
    return 0;
}

ostream& operator<<(ostream& c_out, MyInt my_int)
{
    c_out << my_int.int_;
    return c_out;
}

void Test01()
{
    MyInt num;
    cout << num << endl;
    cout << ++(++num) << endl;
    cout << num << endl;
}

void Test02()
{
    MyInt num;
    cout << num << endl;
    cout << num++ << endl;
    cout << num << endl;
}