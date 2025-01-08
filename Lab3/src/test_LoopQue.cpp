/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-10-22 16:42:04
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-10-22 17:07:53
 * @FilePath: \Lab3\src\test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "SeqLoopQue.h"
#include <windows.h>

using namespace std;

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    LoopQueue<int> queue(5);

    try
    {
        queue.push(10);
        queue.push(20);
        queue.push(30);
        queue.push(40);

        cout << "队列大小: " << queue.getSize() << endl;
        cout << "队头元素: " << queue.getFront() << endl;

        queue.pop();
        cout << "队头元素: " << queue.getFront() << endl;

        queue.pop();
        queue.pop();
        queue.pop(); // 队列为空，下一次调用会触发异常

        cout << "队列大小: " << queue.getSize() << endl;
        // 尝试获取队列为空时的队头，触发异常
        cout << "队头元素: " << queue.getFront() << endl;
    }
    catch (const std::out_of_range &e)
    {
        // 捕获并处理异常，防止程序闪退
        cout << "捕获异常: " << e.what() << endl;
    }
    catch (...)
    {
        // 捕获所有未预料到的异常
        cout << "捕获了一个未知异常" << endl;
    }

    system("pause");

    return 0;
}