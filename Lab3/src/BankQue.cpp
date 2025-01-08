/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-10-27 15:32:52
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-10-27 17:16:45
 * @FilePath: \Lab3\src\BankQue.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <iostream>
#include <string>
#include <windows.h>
#include "LinkLoopQue.h"
using namespace std;

// 使用您已经实现的 Node 和 LinkLoopQue 类...

class BankQueue
{
private:
    LinkLoopQue<int> queue;
    int currentNumber; // 当前号码
    bool isServicing;  // 营业状态

public:
    BankQueue() : currentNumber(0), isServicing(true) {}

    // 取号
    int getNumber()
    {
        if (!isServicing)
        {
            cout << "银行已停止营业，不再接受排队！" << endl;
            return -1;
        }
        currentNumber++;
        queue.push(currentNumber);
        cout << "您的号码是: " << currentNumber << endl;
        cout << "前面还有 " << getPeopleCount(currentNumber) - 1 << " 人在等待" << endl;
        return currentNumber;
    }

    // 叫号服务
    void callNumber()
    {
        if (queue.isEmpty())
        {
            cout << "当前没有等待的顾客" << endl;
            return;
        }
        int number = queue.getFront();
        cout << "请 " << number << " 号顾客前往办理业务" << endl;
        queue.pop();
    }

    // 获取指定号码前面的等待人数
    int getPeopleCount(int number)
    {
        int count = 0;
        if (queue.isEmpty())
            return 0;

        Node<int> *cur = queue.rear->next; // 从头结点的下一个开始
        while (cur != queue.rear)
        {
            if (cur->data < number)
            {
                count++;
            }
            cur = cur->next;
        }
        // 检查队尾节点
        if (queue.rear->data < number)
        {
            count++;
        }
        return count;
    }

    // 停止营业
    void stopService()
    {
        isServicing = false;
        cout << "银行停止营业，不再接受新的排队" << endl;
        cout << "剩余等待顾客数量: " << queue.getSize() << endl;
    }

    // 结束营业并处理剩余顾客
    void closeBank()
    {
        stopService();
        while (!queue.isEmpty())
        {
            cout << "正在处理最后的顾客..." << endl;
            callNumber();
        }
        cout << "所有顾客已处理完毕，银行正式下班" << endl;
    }

    // 顾客主动离开
    void customerLeave(int number)
    {
        cout << "顾客 " << number << " 请求离开队列" << endl;
        queue.remove(number);
    }

    // 显示当前队列状态
    void showCurrentQueue()
    {
        if (queue.isEmpty())
        {
            cout << "当前没有等待的顾客" << endl;
            return;
        }
        cout << "当前等待队列: ";
        queue.display();
    }
};

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    BankQueue bank;
    int choice;
    int number;

    while (true)
    {
        cout << "\n=== 银行排队系统 ===" << endl;
        cout << "1. 取号排队" << endl;
        cout << "2. 叫号服务" << endl;
        cout << "3. 查看当前队列" << endl;
        cout << "4. 顾客离开" << endl;
        cout << "5. 停止营业" << endl;
        cout << "6. 银行下班" << endl;
        cout << "0. 退出系统" << endl;
        cout << "请选择操作: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.getNumber();
            break;
        case 2:
            bank.callNumber();
            break;
        case 3:
            bank.showCurrentQueue();
            break;
        case 4:
            cout << "请输入要离开的号码: ";
            cin >> number;
            bank.customerLeave(number);
            break;
        case 5:
            bank.stopService();
            break;
        case 6:
            bank.closeBank();
            return 0;
        case 0:
            cout << "系统已退出" << endl;
            return 0;
        default:
            cout << "无效的选择，请重新输入" << endl;
        }
        system("pause");
        system("cls");
    }

    return 0;
}