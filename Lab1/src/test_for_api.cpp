#include "CircularLinkList.h"
#include <iostream>

using namespace std;

int main()
{
    CircularLinkList<int> list;
    // 测试指定位置插入元素
    list.insert(1, 10); // 插入到第1个位置
    list.insert(2, 20); // 插入到第2个位置
    list.insert(3, 30); // 插入到第3个位置
    list.insert(4, 40); // 插入到第4个位置
    list.insert(3, 50); // 插入到第3个位置

    // 打印当前链表内容
    std::cout << "链表内容: ";
    list.display();

    try
    {
        // 测试插入位置异常
        list.insert(114514, 1919810);
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    // 测试获取元素
    try
    {
        std::cout << "第2个元素: " << list.getElement(2) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    // 测试获取元素异常
    try
    {
        std::cout << "第233个元素为: " << list.getElement(233) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    // 测试获取前驱和后继元素
    try
    {
        std::cout << "第2个元素的前驱: " << list.getPredecessor(2) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "第2个元素的后继: " << list.getSuccessor(2) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    // // 测试获取前驱后继异常
    try
    {
        std::cout << "第1个元素的前驱: " << list.getPredecessor(1) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    int last = list.length();
    try
    {
        std::cout << "最后一个元素的后继: " << list.getSuccessor(last) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    // 测试元素删除
    try
    {
        list.remove(2);
        std::cout << "删除第2个元素后链表内容: ";
        list.display();
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    // 测试删除元素异常
    try
    {
        list.remove(233);
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    // 测试定位元素
    try
    {
        int position = list.locateElement(30);
        if (position != -1)
        {
            std::cout << "元素30的位置: " << position << std::endl;
        }
        else
        {
            std::cout << "未找到元素30" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }
    try
    {
        int position = list.locateElement(2887);
        if (position != -1)
        {
            std::cout << "元素2887的位置: " << position << std::endl;
        }
        else
        {
            std::cout << "未找到元素2887" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    // 测试头插
    try
    {
        list.insertToHead(42);
        list.display();
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    // 测试尾插
    try
    {
        list.insertToEnd(42);
        list.display();
    }
    catch (const std::exception &e)
    {
        std::cout << "发生异常: " << e.what() << std::endl;
    }

    system("pause");

    return 0;
}
