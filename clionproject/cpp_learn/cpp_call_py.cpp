#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    const char* script_name = "D:/cCode/clionproject/cpp_learn/script.py";
    const char* pattern = "CPP";

    char cmd[265];
    sprintf(cmd, "python %s %s", script_name, pattern);

    FILE *pipe = popen(cmd, "r");
    if (pipe == nullptr)
    {
        cerr << "can't execute python script" << cmd << endl;
        return -1;
    }

    char buf[256];
    string res;
    while (fgets(buf, sizeof(buf), pipe))
    {
        res += buf;
    }

    pclose(pipe);

    cout << "python return: " << res << endl;

    system("pause");
    return 0;
}

