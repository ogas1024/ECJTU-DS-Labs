/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-12-03 17:25:31
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-12-06 16:18:33
 * @FilePath: \Lab6\src\test_SeqSearch.cpp
 * @Description: Coding with UTF-8
 *
 * Copyright (c) 2024 by OGAS, All Rights Reserved.
 */
#include <iostream>
#include <windows.h>
#include "SeqSearch.h"

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    // 测试数据
    int arr1[] = {0, 1, 3, 5, 7, 9, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]) - 1;
    int key1 = 7;

    int arr2[] = {0, 2, 4, 6, 8, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]) - 1;
    int key2 = 5;

    // 测试sequential_search(无哨兵的顺序查找)
    int result1 = sequential_search(arr1, n1, key1);
    if (result1 != -1)
    {
        cout << "测试sequential_search(无哨兵的顺序查找): 查找值 " << key1 << " 在数组中的位置为: " << result1 << " (数组下标从1开始)" << endl;
    }
    else
    {
        cout << "测试sequential_search(无哨兵的顺序查找): 查找值 " << key1 << " 未找到" << endl;
    }

    // 测试sequential_search_2(带哨兵的顺序查找)
    int result2 = sequential_search_2(arr2, n2, key2);
    if (result2 != 0)
    {
        cout << "测试sequential_search_2(带哨兵的顺序查找): 查找值 " << key2 << " 在数组中的位置为: " << result2 << endl;
    }
    else
    {
        cout << "测试sequential_search_2(带哨兵的顺序查找): 查找值 " << key2 << " 未找到" << endl;
    }

    system("pause");
    return 0;
}
