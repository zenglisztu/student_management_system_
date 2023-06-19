//
// Created by 曾立 on 2023/6/11.
//
#include <iostream>
using namespace std;

int main()
{
    long long us_population = 0;
    long long world_population = 0;

    cout << "Enter world's population: ";
    cin >> world_population;
    cout << "Enter the population of the US: ";
    cin >> us_population;
    cout << "The population of the US is " << ((double)us_population / world_population) * 100 << "% of the world population." << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << i << endl;
    }
    return 0;
}