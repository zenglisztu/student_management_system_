//
// Created by 曾立 on 2023/6/20.
//
#include <iostream>
#include <string>

using namespace std;

class Father
{
public:
    int a_;
protected:
    int b_;
private:
    int c_;
};

class Son:public Father
{
public:
    int d_;
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
    Son s_1 = Son();
    s_1.a_ = 100;
    //s_1.b_ = 200;
    cout << s_1.a_ << endl;
}