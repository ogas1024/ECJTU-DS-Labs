/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-10-11 10:54:47
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-10-11 22:46:25
 * @FilePath: \Lab2\src\interface.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <windows.h>
#include "in2post.h"
#include "postCal.h"
#include "tools.h"

using namespace std;

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    string infix;
    vector<string> postfix;

    while (true)
    {
        puts("后缀表达式计算器");
        puts("1. 前缀表达式转后缀表达式, 并计算");
        puts("2. 后缀表达式计算");
        puts("0. 退出");
        puts("请选择操作：");
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "请输入前缀表达式：(空格分割各个部分, 例如: 1 + 1)" << endl;
            cin.ignore();        // 忽略之前的换行符
            getline(cin, infix); // 使用getline读取整行输入
            cout << "后缀表达式为：" << endl;
            postfix = in2post::infixToPostfix(infix); // 调用前缀转后缀函数
            printVector(postfix);
            cout << "计算结果为：" << endl;
            cout << calculatePostfix(postfix) << endl; // 调用后缀表达式计算函数
            system("pause");
            break;
        case 2:
            postfix = inputPostfix(); // 调用输入后缀表达式函数
            cout << "计算结果为：" << endl;
            cout << calculatePostfix(postfix) << endl; // 调用后缀表达式计算函数
            system("pause");
            break;
        case 0:
            return 0;
        }
        system("cls");
    }
    system("pause");
    return 0;
}