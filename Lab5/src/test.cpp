/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-11-23 21:34:50
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-11-23 22:16:55
 * @FilePath: \Lab5\src\test.cpp
 * @Description: Coding with UTF-8
 *
 * Copyright (c) 2024 by OGAS, All Rights Reserved.
 */
#include "AdjacencyMatrixGraph.h"
#include <iostream>
#include <stdexcept>
#include <windows.h>

using namespace std;

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    try
    {
        // 定义顶点数组
        char vertices[] = {'A', 'B', 'C', 'D', 'E'};
        int n = 5;              // 顶点个数
        int e = 7;              // 边数
        bool isDireced = false; // 是否有向图

        // 创建图对象
        AMGraph<char, int> graph(vertices, n, e);

        // 输入边的信息
        graph.addEdge(0, 1, 7, isDireced);  // A-B
        graph.addEdge(0, 2, 9, isDireced);  // A-C
        graph.addEdge(0, 4, 14, isDireced); // A-E
        graph.addEdge(1, 2, 10, isDireced); // B-C
        graph.addEdge(1, 3, 15, isDireced); // B-D
        graph.addEdge(2, 3, 11, isDireced); // C-D
        graph.addEdge(2, 4, 2, isDireced);  // C-E

        // 打印图的信息
        graph.printGraph();

        // 测试DFS和BFS
        cout << "\nDFS遍历: ";
        graph.DFS(0);
        cout << "\nBFS遍历: ";
        graph.BFS(0);

        // 测试Prim算法
        graph.Prim(0);

        // 测试Kruskal算法
        graph.Kruskal();

        // 测试Dijkstra算法
        graph.Dijkstra(0);

        // 测试Floyd算法
        graph.Floyd();
    }
    catch (const exception &e)
    {
        cerr << "An error occurred: " << e.what() << endl;
        return 1;
    }

    system("pause");
    return 0;
}
