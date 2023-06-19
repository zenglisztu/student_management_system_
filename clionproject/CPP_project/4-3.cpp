//
// Created by 曾立 on 2023/6/11.
//
#include <iostream>
using namespace std;

int main()
{
    const int ArSize = 20;
    char name[ArSize] = {0};
    char university[ArSize] = {0};

    cout << "Enter your name: ";
    cin.getline(name, ArSize);
    cout << "Enter your university: ";
    cin.getline(university, ArSize);

    cout << name << "'s university is " << university << endl;

    return 0;
}