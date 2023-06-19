//
// Created by 曾立 on 2023/6/19.
//
#include <iostream>
#include <string>

using namespace std;

class Building
{
    friend class GoodFriend;

public:
    explicit Building(string&& sitting_room = "客厅", string&& bed_room = "卧室");

    string sitting_room_;
private:
    string bed_room_;
};

class GoodFriend
{
public:
    GoodFriend();
    void Visit() const;

    Building * house;
    ~GoodFriend()
    {
        if (house != nullptr)
        {
            delete house;
        }
    }
};

void Test01();

int main(int argc, char *argv[])
{
    Test01();

    system("pause");
    return 0;
}

GoodFriend::GoodFriend()
{
    GoodFriend::house = new Building;
}

void GoodFriend::Visit() const
{
    cout << "正在访问" << house->sitting_room_ << endl;
    cout << "正在访问" << house->bed_room_ << endl;
}

Building::Building(string&& sitting_room, string&& bed_room):
sitting_room_(std::move(sitting_room)),
bed_room_(std::move(bed_room))
{

}

void Test01()
{
    GoodFriend gf;
    gf.Visit();
}