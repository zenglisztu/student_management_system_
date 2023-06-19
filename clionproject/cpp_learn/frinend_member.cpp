//
// Created by ÔøÁ¢ on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Building
{
    friend void GoodFriend(Building& home);
public:

    explicit Building(string&& sitting_room = "¿ÍÌü", string&& bed_room = "ÎÔÊÒ"):
    sitting_room_(std::move(sitting_room)),
    bed_room_(std::move(bed_room))
    {}

    string sitting_room_;
private:
    string bed_room_;
};

void Test01();
void GoodFriend(Building& home);
int main()
{
    Test01();

    system("pause");
    return 0;
}

void Test01()
{
    Building home;
    GoodFriend(home);
}

void GoodFriend(Building& home)
{
    cout << home.sitting_room_ << endl;
    cout << home.bed_room_ << endl;
}