//
// Created by 曾立 on 2023/6/21.
//
#include <iostream>
#include <cstdio>

std::string& RunPythonFile(const char *file_path, const char *parameter,std::string& result);

int main(int argc, char *argv[])
{
    const char* script_name = "D:/cCode/clionproject/cpp_learn/read_excel.py";
    //（打开excel的参数，参数间用空格隔开）excel路径 读写方式 工作表下标
    const char* pattern = "D:/dome/Excel/中德智能制造学院课程.xlsx r 0";
    std::string result;

    std::cout <<RunPythonFile(script_name, pattern, result) << std::endl;

    system("pause");
    return 0;
}

std::string& RunPythonFile(const char *file_path, const char *parameter, std::string& result)
{
    //拼接cmd命令
    std::string cmd = "python " + std::string(file_path) + " " + std::string(parameter);

    // 创建管道
    FILE *pipe = popen(cmd.c_str(), "r");
    if (pipe == nullptr)
    {
        return result;
    }

    // 读取管道输出的内容
    char buf[256] = {0};
    while (fgets(buf, sizeof(buf), pipe))
    {
        result += buf;
    }

    // 关闭管道
    pclose(pipe);

    return result;
}