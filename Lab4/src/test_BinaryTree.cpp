/*
 * @Author: OGAS 2970143166@qq.com
 * @Date: 2024-11-08 23:01:12
 * @LastEditors: OGAS 2970143166@qq.com
 * @LastEditTime: 2024-11-08 23:14:06
 * @FilePath: \Lab4\src\test_BinaryTree.cpp
 * @Description:
 * Coding with UTF-8
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved.
 */
#include <cassert>
#include <sstream>
#include <windows.h>
#include "BinaryTree.h"

void testBinaryTree()
{
    // 创建测试树
    //       1
    //      / \
    //     2   3
    //    /     \
    //   4       5

    BinaryTree<int> tree;

    // 手动创建一个测试用的二叉树
    tree.root = new BinaryTreeNode<int>();
    tree.root->data = 1;

    tree.root->left = new BinaryTreeNode<int>();
    tree.root->left->data = 2;

    tree.root->right = new BinaryTreeNode<int>();
    tree.root->right->data = 3;

    tree.root->left->left = new BinaryTreeNode<int>();
    tree.root->left->left->data = 4;

    tree.root->right->right = new BinaryTreeNode<int>();
    tree.root->right->right->data = 5;

    // 1. 测试节点计数
    cout << "测试节点计数..." << endl;
    int nodeCount = tree.countNodes(tree.root);
    cout << "节点总数: " << nodeCount << endl;
    assert(nodeCount == 5);

    // 2. 测试叶子节点计数
    cout << "测试叶子节点计数..." << endl;
    int leafCount = tree.countLeaves(tree.root);
    cout << "叶子节点数: " << leafCount << endl;
    assert(leafCount == 2);

    // 3. 测试树的深度
    cout << "测试树的深度..." << endl;
    int depth = tree.getDepth(tree.root);
    cout << "树的深度: " << depth << endl;
    assert(depth == 3);

    // 4. 测试树的遍历
    cout << "\n测试各种遍历方式:" << endl;

    cout << "前序遍历: ";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "中序遍历: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "后序遍历: ";
    tree.postOrder(tree.root);
    cout << endl;

    cout << "层序遍历: ";
    tree.levelOrder(tree.root);
    cout << endl;

    // 5. 测试左右子树交换
    cout << "\n测试左右子树交换..." << endl;
    cout << "交换前层序遍历: ";
    tree.levelOrder(tree.root);
    cout << endl;

    tree.swapSubtrees(tree.root);

    cout << "交换后层序遍历: ";
    tree.levelOrder(tree.root);
    cout << endl;

    // 6. 清理内存
    tree.destroy(tree.root);
    cout << "\n所有测试完成" << endl;
}

int main()
{
    // 设置终端输出的字符集为UTF-8
    SetConsoleOutputCP(CP_UTF8);
    // 设置终端输入的字符集为UTF-8
    SetConsoleCP(CP_UTF8);

    testBinaryTree();

    system("pause");
    return 0;
}