//
// Created by ���� on 2023/6/21.
//
#include <iostream>
#include <cstdio>

std::string& RunPythonFile(const char *file_path, const char *parameter,std::string& result);

int main(int argc, char *argv[])
{
    const char* script_name = "D:/cCode/clionproject/cpp_learn/read_excel.py";
    //����excel�Ĳ������������ÿո������excel·�� ��д��ʽ �������±�
    const char* pattern = "D:/dome/Excel/�е���������ѧԺ�γ�.xlsx r 0";
    std::string result;

    std::cout <<RunPythonFile(script_name, pattern, result) << std::endl;

    system("pause");
    return 0;
}

std::string& RunPythonFile(const char *file_path, const char *parameter, std::string& result)
{
    //ƴ��cmd����
    std::string cmd = "python " + std::string(file_path) + " " + std::string(parameter);

    // �����ܵ�
    FILE *pipe = popen(cmd.c_str(), "r");
    if (pipe == nullptr)
    {
        return result;
    }

    // ��ȡ�ܵ����������
    char buf[256] = {0};
    while (fgets(buf, sizeof(buf), pipe))
    {
        result += buf;
    }

    // �رչܵ�
    pclose(pipe);

    return result;
}