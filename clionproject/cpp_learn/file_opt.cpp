//
// Created by ���� on 2023/6/20.
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
    ofs << "���ڼ�����ѧ" << endl;
    ofs << "�е���������ѧԺ"  << endl;
    ofs << "����" << endl;
    ofs.close();
}

void ReadFile()
{
    ifstream ifs;
    ifs.open("./out.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ���ʧ�ܣ�" <<endl;
        return;
    }
    char buf[1024] = {0};
    while(ifs >> buf)
    {
        cout << buf << endl;
    }
    
    ifs.close();
}