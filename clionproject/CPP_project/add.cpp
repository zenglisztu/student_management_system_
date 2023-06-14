//
// Created by 曾立 on 2023/6/14.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
public:

    string m_name_f;
    string m_name_l;
    string m_id;
    int m_score;
    int m_retake;
    string m_gpa;

    Student(string name_f, string name_l, string id, int score)
    {
        this->m_name_f = name_f;
        this->m_name_l = name_l;
        this->m_id = id;
        this->m_score = score;
        this->m_retake = this->IsRetake(this->m_id);
        this->m_gpa = this->CalcGpa(this->m_score);
    }

    int IsRetake(string id)
    {
        if (id.substr(0, 4) == "2022")
        {
            return 0;
        }
        return 1;
    }

    string CalcGpa(int score)
    {
        if (score >= 93)
            return "A+";
        else if (score >= 85)
            return "A";
        else if (score >= 80)
            return "B+";
        else if (score >= 75)
            return "B";
        else if (score >= 70)
            return "C+";
        else if (score >= 65)
            return "C";
        else if (score >= 60)
            return "D";
        else
            return "F";
    }

    void ShowInfo() const
    {
        cout << this->m_name_f << " ";
        cout << this->m_name_l << " ";
        cout << this->m_id << " ";
        cout << this->m_score << " ";
        cout << this->m_retake << " ";
        cout << this->m_gpa << "\n";
    }

};


vector<string> SplitString(const string& str, const string& delimiter);
vector<Student> Add(vector<Student> &stus, const string &stu_data);
int Init(vector<Student> &stus);
void PrintAllStu(vector<Student> &stus);
int CheckId(const string &id);
int CheckSCore(const string &score);

int main()
{
    string stu_data;

    vector<Student> vt_stus;
    Init(vt_stus);
    while (getline(cin, stu_data))
    {
        if (stu_data.empty())
        {
            break;
        }
        Add(vt_stus, stu_data);
    }
    cout << "Name_f Name_l stu_id score retake GPA" << endl;
    PrintAllStu(vt_stus);
    cout << "Total: " << vt_stus.size() << endl;
    return 0;
}

vector<string> SplitString(const string &str, const string &delimiter)
{
    vector<string> res_vct;

    size_t start_pos = 0;
    size_t end_pos;

    while ((end_pos = str.find(delimiter, start_pos)) != string::npos)
    {
        res_vct.push_back(str.substr(start_pos, end_pos - start_pos));
        start_pos = end_pos + delimiter.length();
    }
    res_vct.push_back(str.substr(start_pos));

    return res_vct;
}

int CheckId(const string &id)
{
    vector<string> id_starts = {"2022", "2021", "2020"};

    //判断学号长度是否合法
    if (id.size() != 12)
    {
        return 0;
    }

    //判断学号开头四位是否合法
    for (const auto &id_start : id_starts)
    {
        if(id.substr(0, 4) == id_start)
        {
            return 1;
        }
    }

    return 0;
}

int CheckSCore(const string &score)
{
    if (stoi(score) >= 0 && stoi(score) <= 100)

        return 1;

    return 0;
}


vector<Student> Add(vector<Student> &stus, const string &stu_data)
{
    vector<string> data_s = SplitString(stu_data, " ");

    if (CheckId(data_s[2]) && CheckSCore(data_s[3]))
    {
        Student stu(data_s[0], data_s[1], data_s[2], stoi(data_s[3]));
        stus.push_back(stu);
    }

    return stus;
}

int Init(vector<Student> &stus)
{
    Add(stus, "Jingyu LI 202200000000 85");
    Add(stus, "Jy LEE 202200100000 89");
    Add(stus, "Jxxxyx Leeeee 202100100000 100");
    Add(stus, "Jingyu11 LI 202200000001 85");

    return 0;
}

void PrintAllStu(vector<Student> &stus)
{
    for (auto stu : stus)
    {
        stu.ShowInfo();
    }
}