/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-10-11 21:06:13
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-10-11 23:17:20
 * @FilePath: \Lab2\src\in2post_test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <windows.h>
#include <iostream>
#include "in2post.h"
#include "tools.h"

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);
    string infix = "a + b * c - d / e";
    vector<string> postfix = in2post::infixToPostfix(infix);

    cout << "中缀表达式: " << infix << endl;
    cout << "后缀表达式: ";
    for (const string &token : postfix)
    {
        cout << token << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
