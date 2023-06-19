//
// Created by 曾立 on 2023/6/11.
//
#include <iostream>
using namespace std;

int main()
{
    int secs = 0;
    int day = 0;
    int hour = 0;
    int min = 0;
    int sec = 0;

    cout << "Enter the number of seconds: ";
    cin >> secs;

    sec = secs % 60;
    min = (secs / 60) % 60;
    hour = ((secs / 60) / 60)  % 24;
    day = (((secs / 60) / 60)  / 24);

    cout << secs << " seconds = " << day << " days, "
                << hour << " hours, " << min << " minutes, "
                << sec << " seconds" << endl;
    //cout << secs / 60 << " " << (secs / 60) / 60 << " " << ((secs / 60) / 60)  / 24 << endl;

    return 0;
}