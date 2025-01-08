/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-10-11 23:21:04
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-10-11 23:23:15
 * @FilePath: \Lab2\src\postCal_test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <windows.h>
#include <iostream>
#include "postCal.h"
#include "in2post.h"
#include "tools.h"

using namespace std;

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    // 测试表达式: (3 + 4) * (5 - 2) ^ 2
    string infix = "( 3 + 4 ) * ( 5 - 2 ) ^ 2";
    vector<string> postfix = in2post::infixToPostfix(infix);
    double result = calculatePostfix(postfix);

    cout << "原始中缀表达式: " << infix << endl;
    cout << "转换后的后缀表达式: ";
    for (string &token : postfix)
    {
        cout << token << " ";
    }
    cout << endl;
    cout << "计算结果: " << result << endl;

    system("pause");
    return 0;
}
