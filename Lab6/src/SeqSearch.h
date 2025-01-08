/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-12-03 17:12:36
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-12-03 17:32:54
 * @FilePath: \Lab6\src\SeqSearch.h
 * @Description: Coding with UTF-8
 *
 * Copyright (c) 2024 by OGAS, All Rights Reserved.
 */

#include <iostream>

using namespace std;

template <typename T>
int sequential_search(T *a, int n, T key)
{ 
    // a为数组, n为要查找的数组长度, key为要查找的关键字
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == key)
        {
            return i; // 如果查到了, 就返回下标
        }
    }

    return -1; // 如果遍历完了还没查到, 就返回-1
}

// 有哨兵顺序查找
template <typename T>
int sequential_search_2(T *a, int n, T key)
{
    a[0] = key;         // 这里就把之前没用的a[0]利用起来了, 作为哨兵, 存储关键字值
    int i = n;              // 循环从最后一位开始
    while (a[i] != key) // 直到找到key为止, 一旦找到key就跳出循环
    {
        i--;
    }
    return i; // 如果找到key, i即为数组下标, 如果没找到会返回0
}