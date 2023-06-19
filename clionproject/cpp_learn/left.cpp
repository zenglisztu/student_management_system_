//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Person
{
    friend ostream& operator<<(ostream& c_out, Person& p);
public:
    Person(int age, int score):
    age_(age),
    score_(score)
    {}

private:

    int age_;
    int score_;
};

ostream& operator<<(ostream& c_out, Person& p);
void Text();

int main(int argc, char *argv[])
{
    Text();
    system("pause");
    return 0;
}

void Text()
{
    Person p(18, 100);
    cout << p << endl;
}

ostream& operator<<(ostream& c_out, Person& p)
{
    c_out << "{\'" << "age_ :" << p.age_ << "\', " << "\'" << "score_ :" << p.score_ << "\'}";
    return c_out;
}