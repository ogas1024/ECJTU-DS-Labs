#include "CircularLinkList.h"
#include <iostream>

using namespace std;

int main()
{
    CircularLinkList<int> list;
    // ����ָ��λ�ò���Ԫ��
    list.insert(1, 10); // ���뵽��1��λ��
    list.insert(2, 20); // ���뵽��2��λ��
    list.insert(3, 30); // ���뵽��3��λ��
    list.insert(4, 40); // ���뵽��4��λ��
    list.insert(3, 50); // ���뵽��3��λ��

    // ��ӡ��ǰ��������
    std::cout << "��������: ";
    list.display();

    try
    {
        // ���Բ���λ���쳣
        list.insert(114514, 1919810);
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    // ���Ի�ȡԪ��
    try
    {
        std::cout << "��2��Ԫ��: " << list.getElement(2) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    // ���Ի�ȡԪ���쳣
    try
    {
        std::cout << "��233��Ԫ��Ϊ: " << list.getElement(233) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    // ���Ի�ȡǰ���ͺ��Ԫ��
    try
    {
        std::cout << "��2��Ԫ�ص�ǰ��: " << list.getPredecessor(2) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "��2��Ԫ�صĺ��: " << list.getSuccessor(2) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    // // ���Ի�ȡǰ������쳣
    try
    {
        std::cout << "��1��Ԫ�ص�ǰ��: " << list.getPredecessor(1) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    int last = list.length();
    try
    {
        std::cout << "���һ��Ԫ�صĺ��: " << list.getSuccessor(last) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    // ����Ԫ��ɾ��
    try
    {
        list.remove(2);
        std::cout << "ɾ����2��Ԫ�غ���������: ";
        list.display();
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    // ����ɾ��Ԫ���쳣
    try
    {
        list.remove(233);
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    // ���Զ�λԪ��
    try
    {
        int position = list.locateElement(30);
        if (position != -1)
        {
            std::cout << "Ԫ��30��λ��: " << position << std::endl;
        }
        else
        {
            std::cout << "δ�ҵ�Ԫ��30" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }
    try
    {
        int position = list.locateElement(2887);
        if (position != -1)
        {
            std::cout << "Ԫ��2887��λ��: " << position << std::endl;
        }
        else
        {
            std::cout << "δ�ҵ�Ԫ��2887" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    // ����ͷ��
    try
    {
        list.insertToHead(42);
        list.display();
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    // ����β��
    try
    {
        list.insertToEnd(42);
        list.display();
    }
    catch (const std::exception &e)
    {
        std::cout << "�����쳣: " << e.what() << std::endl;
    }

    system("pause");

    return 0;
}
