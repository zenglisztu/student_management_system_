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

int main()
{
    string stu_data;
    int n = 5;

    vector<Student> vt_stus;
    while (n)
    {
        getline(cin, stu_data);
        vector<string> v_data = SplitString(stu_data, " ");
        Student stu_1(v_data[0], v_data[1], v_data[2], stoi(v_data[3]));
        vt_stus.push_back(stu_1);
        n--;
    }
    cout << "Name_f Name_l stu_id score retake GPA rank" << endl;
    for (int i = 0; i < vt_stus.size(); ++i)
    {
        vt_stus[i].ShowInfo();
    }

    return 0;
}

vector<string> SplitString(const string& str, const string& delimiter)
{
    vector<string> tokens;

    size_t startPos = 0, endPos;
    while ((endPos = str.find(delimiter, startPos)) != string::npos) {
        tokens.push_back(str.substr(startPos, endPos - startPos));
        startPos = endPos + delimiter.length();
    }
    tokens.push_back(str.substr(startPos));

    return tokens;
}