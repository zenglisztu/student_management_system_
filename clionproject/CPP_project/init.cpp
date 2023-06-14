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

    void ShowInfo()
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
int CheckId(const string &id);

int main()
{
    string stu_data;
    int n = 5;

    vector<Student> vt_stus;
    while (getline(cin, stu_data))
    {
        if (stu_data.empty())
        {
            break;
        }
        //getline(cin, stu_data);
        vector<string> v_data = SplitString(stu_data, " ");
        if (CheckId(v_data[2]))
        {
            Student stu_1(v_data[0], v_data[1], v_data[2], stoi(v_data[3]));
            vt_stus.push_back(stu_1);
        }
    }
    cout << "Name_f Name_l stu_id score retake GPA rank" << endl;
    for (int i = 0; i < vt_stus.size(); ++i)
    {
        vt_stus[i].ShowInfo();
    }

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
    vector<string> id_start = {"2022", "2021", "2020"};

    //判断学号长度是否合法
    if (id.size() != 12)
    {
        return 0;
    }

    //判断学号开头四位是否合法
    for (size_t i = 0; i < id_start.size(); ++i)
    {
        if(id.substr(0, 4) == id_start[i])
        {
            return 1;
        }
    }

    return 0;
}