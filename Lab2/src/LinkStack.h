#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Node
{
public:
    Node(T t) : value(t), next(nullptr) {}
    Node() : next(nullptr) {}

public:
    T value;
    Node<T> *next;
};

template <typename T>
class LinkStack
{
public:
    LinkStack();
    ~LinkStack();

    bool isEmpty();
    int getSize();
    void push(const T &t);
    void pop();
    T getTop();

private:
    Node<T> *top;
    int cnt;
};

// 构造函数：初始化top指针和cnt
template <typename T>
LinkStack<T>::LinkStack() : top(nullptr), cnt(0) {}

// 析构函数：释放所有节点内存，避免内存泄漏
template <typename T>
LinkStack<T>::~LinkStack()
{
    while (!isEmpty())
    {
        pop();
    }
}

// 获取栈的大小
template <typename T>
int LinkStack<T>::getSize()
{
    return cnt;
}

// 判断栈是否为空
template <typename T>
bool LinkStack<T>::isEmpty()
{
    return cnt == 0;
}

// 入栈：创建一个新节点，并将其放到栈顶
template <typename T>
void LinkStack<T>::push(const T &t)
{
    Node<T> *pnode = new Node<T>(t);
    pnode->next = top; // 新节点指向当前栈顶
    top = pnode;       // 更新栈顶指针
    cnt++;             // 更新栈的大小
}

// 出栈：删除栈顶节点
template <typename T>
void LinkStack<T>::pop()
{
    if (isEmpty())
    {
        throw out_of_range("栈为空，无法出栈");
    }
    Node<T> *pdel = top; // 暂存栈顶节点
    top = top->next;     // 更新栈顶指针
    delete pdel;         // 删除原栈顶节点
    cnt--;               // 更新栈的大小
}

// 获取栈顶元素：返回栈顶元素的值，不修改栈结构
template <typename T>
T LinkStack<T>::getTop()
{
    if (isEmpty())
    {
        throw out_of_range("栈为空，无法获取栈顶元素");
    }
    return top->value; // 返回栈顶节点的值
}
