/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-12-06 16:22:31
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-12-06 16:34:03
 * @FilePath: \Lab6\src\test_HashMap.cpp
 * @Description: Coding with UTF-8
 *
 * Copyright (c) 2024 by OGAS, All Rights Reserved.
 */
#include <iostream>
#include <windows.h>
#include "HashMap(OpenAddr).h"

using namespace std;

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    HashMap hashMap;

    // 插入关键字序列
    int keys[] = {12, 9, 15, 10, 8, 21, 3, 29, 30, 11, 40, 7};
    for (int i = 0; i < 12; i++)
    {
        hashMap.insert(keys[i]);
    }

    // 查找关键字15
    int position = hashMap.find(15);
    if (position != 0x3f3f3f3f)
    {
        cout << "关键字15在哈希表中的位置为: " << position << endl;
    }
    else
    {
        cout << "关键字15不在哈希表中" << endl;
    }

    system("pause");
    return 0;
}