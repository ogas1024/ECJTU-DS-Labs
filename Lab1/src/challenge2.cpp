#include "CircularLinkList.h"
#include <iostream>
#include <iterator>
#include <windows.h>

void findRabbit(CircularLinkList<int> &holes, int rabbit_position)
{
    // ����һ������������ʾ����ĵ�ǰλ�ã���ʼʱ������1�Ŷ�
    ListNode<int> *fox = holes.getHead();
    fox = fox->next;

    // ��ʼ����Ծ��������һ�θ�0�������ڶ��θ�1�������Դ�����
    int jump = 0;

    // ���꿪ʼѰ������
    for (int attempts = 0; attempts < 1000; ++attempts)
    {
        // �������Ƿ��ҵ�������
        if (fox->data == rabbit_position)
        { // *fox == rabbit_position
            std::cout << "�����ڵ� " << attempts + 1 << " ���ҵ����ӣ����Ӳ��� " << rabbit_position << " �Ŷ���" << std::endl;
            system("pause");
            return;
        }

        // ���º������Ծ��������Ծ����Ϊ��ǰ����+1��
        jump++;

        // ������ݹ�����Ծ
        for (int i = 0; i <= jump; ++i)
        {
            // ��������б�ĩβ������ѭ�����б�ʼ
            fox = fox->next;
            if (fox == holes.getTail())
            {
                fox = holes.getHead()->next;
            }
        }
    }

    std::cout << "�����Ӳ��� " << rabbit_position << " ʱ���꾭��1000�β�����δ�ҵ����ӡ�" << std::endl;
    system("pause");
    return;
}

// �������ʽ����utf-8
inline void setOutputEncoding()
{
    SetConsoleOutputCP(CP_UTF8);
}

int main()
{
    // setOutputEncoding();

    // ��ʼ����������Ϊ10�����������1��10
    CircularLinkList<int> holes;
    for (int i = 1; i <= 10; ++i)
    {
        holes.insert(holes.length() + 1, i);
    }

    // �������Ӳ����ĸ�����, �����в���
    for (int rabbit_position = 1; rabbit_position <= 10; ++rabbit_position)
    {
        findRabbit(holes, rabbit_position);
    }

    return 0;
}
