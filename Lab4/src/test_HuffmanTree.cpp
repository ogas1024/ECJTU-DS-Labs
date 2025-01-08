/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-11-09 18:09:08
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-11-09 18:13:09
 * @FilePath: \Lab4\src\test_HuffmanTree.cpp
 * @Description: Coding with UTF-8
 *
 * Copyright (c) 2024 by OGAS, All Rights Reserved.
 */
#include "HuffmanTree.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    // 创建测试用的字符频率表
    map<char, int> weights = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}};

    // 创建哈夫曼树对象
    HuffmanTree huffman;

    // 构建哈夫曼树
    huffman.buildTree(weights);

    // 打印编码表
    huffman.printCodes();

    // 测试编码和解码
    string text = "abcdef";
    cout << "\n原字符串: " << text << endl;

    // 编码
    string encoded = huffman.encode(text);
    cout << "源字符串经过哈夫曼编码后的字符串: " << encoded << endl;

    // 解码
    string decoded = huffman.decode(encoded);
    cout << "编码后的字符串解码出的字符串: " << decoded << endl;

    system("pause");
    return 0;
}