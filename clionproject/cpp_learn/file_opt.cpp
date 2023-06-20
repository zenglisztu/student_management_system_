//
// Created by 曾立 on 2023/6/20.
//
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void WriteFile();
void ReadFile();
int main(int argc, char *argv[])
{
    //WriteFile();
    ReadFile();
    system("pause");
    return 0;
}

void WriteFile()
{
    ofstream ofs;
    ofs.open("./out.txt", ios::out);
    ofs << "深圳技术大学" << endl;
    ofs << "中德智能制造学院"  << endl;
    ofs << "曾立" << endl;
    ofs.close();
}

void ReadFile()
{
    ifstream ifs;
    ifs.open("./out.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" <<endl;
        return;
    }
    char buf[1024] = {0};
    while(ifs >> buf)
    {
        cout << buf << endl;
    }
    
    ifs.close();
}