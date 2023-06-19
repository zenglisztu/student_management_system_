//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(int age, int score, int weight):age(age), score(score), weight(weight)
    {

    }

    int age;
    int score;
    int weight;
};


int main()
{

    Person p1(18, 100, 50);

    cout << "p1 age is " << p1.age << endl;
    cout << "p1 score is " << p1.score << endl;
    cout << "p1 weight is" << p1.weight << endl;

    system("pause");

    return 0;
}