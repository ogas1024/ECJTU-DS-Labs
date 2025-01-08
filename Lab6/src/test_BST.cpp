/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-12-06 16:40:16
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-12-06 17:29:17
 * @FilePath: \Lab6\src\test_BST.cpp
 * @Description: Coding with UTF-8
 *
 * Copyright (c) 2024 by OGAS, All Rights Reserved.
 */
#include <iostream>
#include <windows.h>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    BSTree<int> bst;

    // 插入元素
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    // 中序遍历
    cout << "插入{5,3,7,2,4,6,8}之后的中序遍历结果为: ";
    bst.inOrder();
    cout << endl;

    // 删除元素
    bst.remove(3);

    // 中序遍历
    cout << "删除{3}之后的中序遍历结果为: ";
    bst.inOrder();
    cout << endl;

    // 再次插入元素
    bst.insert(1);
    bst.insert(9);
    bst.insert(10);

    // 中序遍历
    cout << "再次插入{1,9,10}之后的中序遍历结果为: ";
    bst.inOrder();
    cout << endl;

    system("pause");
    return 0;
}