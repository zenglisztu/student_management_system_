//
// Created by 曾立 on 2023/6/20.
//
#include <iostream>
#include <Python.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{

    Py_Initialize();
    string py_cnt;

    py_cnt += "result = len(hello world!)";
    PyRun_SimpleString(py_cnt.c_str());


    Py_Finalize();
    system("pause");

    return 0;
}