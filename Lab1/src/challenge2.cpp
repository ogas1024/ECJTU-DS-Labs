#include "CircularLinkList.h"
#include <iostream>
#include <iterator>
#include <windows.h>

void findRabbit(CircularLinkList<int> &holes, int rabbit_position)
{
    // 创建一个迭代器来表示狐狸的当前位置，开始时狐狸在1号洞
    ListNode<int> *fox = holes.getHead();
    fox = fox->next;

    // 初始化跳跃步数，第一次隔0个洞，第二次隔1个洞，以此类推
    int jump = 0;

    // 狐狸开始寻找兔子
    for (int attempts = 0; attempts < 1000; ++attempts)
    {
        // 检查狐狸是否找到了兔子
        if (fox->data == rabbit_position)
        { // *fox == rabbit_position
            std::cout << "狐狸在第 " << attempts + 1 << " 次找到兔子，兔子藏在 " << rabbit_position << " 号洞。" << std::endl;
            system("pause");
            return;
        }

        // 更新狐狸的跳跃步数（跳跃步数为当前步数+1）
        jump++;

        // 狐狸根据规则跳跃
        for (int i = 0; i <= jump; ++i)
        {
            // 如果到达列表末尾，重新循环到列表开始
            fox = fox->next;
            if (fox == holes.getTail())
            {
                fox = holes.getHead()->next;
            }
        }
    }

    std::cout << "当兔子藏在 " << rabbit_position << " 时狐狸经过1000次查找仍未找到兔子。" << std::endl;
    system("pause");
    return;
}

// 将输出格式换成utf-8
inline void setOutputEncoding()
{
    SetConsoleOutputCP(CP_UTF8);
}

int main()
{
    // setOutputEncoding();

    // 初始化洞的数量为10，并给洞编号1到10
    CircularLinkList<int> holes;
    for (int i = 1; i <= 10; ++i)
    {
        holes.insert(holes.length() + 1, i);
    }

    // 定义兔子藏在哪个洞里, 并进行查找
    for (int rabbit_position = 1; rabbit_position <= 10; ++rabbit_position)
    {
        findRabbit(holes, rabbit_position);
    }

    return 0;
}
