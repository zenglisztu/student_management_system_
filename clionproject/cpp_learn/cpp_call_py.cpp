#include <iostream>
#include <cstdio>
#include <cstring>

std::string& RunPythonFile(const char *file_path, const char *parameter,std::string& result);

int main(int argc, char *argv[])
{
    const char* script_name = "D:/cCode/clionproject/cpp_learn/script.py";
    const char* pattern = "CPP";
    std::string result;

    std::cout <<RunPythonFile(script_name, pattern, result) << std::endl;

    system("pause");
    return 0;
}

std::string& RunPythonFile(const char *file_path, const char *parameter, std::string& result) {
    // 将文件路径和参数进行拼接
    size_t cmd_size = strlen(file_path) + strlen(parameter) + 10; // 加上常规字符数，如空格、\0 等
    char *cmd = new char[cmd_size];
    memset(cmd, 0, cmd_size);
    sprintf(cmd, "python %s %s", file_path, parameter);

    // 创建管道
    FILE *pipe = popen(cmd, "r");
    if (pipe == nullptr)
    {
        delete[] cmd;
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
    // 释放内存
    delete[] cmd;

    return result;
}