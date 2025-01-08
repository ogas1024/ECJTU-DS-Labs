/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-10-27 00:03:40
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-10-27 16:38:35
 * @FilePath: \Lab3\src\teat_LinkLoopQue.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include "LinkLoopQue.h"
#include <windows.h>

using namespace std;

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    LinkLoopQue<int> queue;

    try
    {
        // 测试入队
        queue.push(1);
        queue.push(2);
        queue.push(3);

        cout << "当前大小: " << queue.getSize() << endl; // 3

        cout << "队头: " << queue.getFront() << endl; // 1
        cout << "队尾: " << queue.getRear() << endl;  // 3

        // 测试出队
        queue.pop();
        cout << "出队后的队头: " << queue.getFront() << endl; // 2
        cout << "当前大小: " << queue.getSize() << endl;      // 2

        // 测试清空
        queue.clear();
        cout << "清空后测试判空: " << queue.isEmpty() << endl; // true
        cout << "当前大小: " << queue.getSize() << endl;       // 0

        // 测试空队列异常
        // queue.pop(); // 将抛出异常
    }
    catch (const runtime_error &e)
    {
        cout << "异常: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "未知异常" << endl;
    }
    system("pause");
    return 0;
}