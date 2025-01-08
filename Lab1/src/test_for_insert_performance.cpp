#include "CircularLinkList.h"
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;
using namespace std::chrono;

void testInsertPerformance(int size, int repeatCount)
{
    CircularLinkList<int> list;

    // 预先填充列表
    for (int i = 0; i < size; ++i)
    {
        list.insertToEnd(i);
    }

    // 测试 insertToHead
    auto start = high_resolution_clock::now();
    for (int i = 0; i < repeatCount; ++i)
    {
        list.insertToHead(i);
        list.remove(1); // 为保持大小不变，插入后立即删除
    }
    auto end = high_resolution_clock::now();
    auto durationHead = duration_cast<microseconds>(end - start);

    // 测试 insertToEnd
    start = high_resolution_clock::now();
    for (int i = 0; i < repeatCount; ++i)
    {
        list.insertToEnd(i);
        list.remove(list.length()); // 为保持大小不变，插入后立即删除
    }
    end = high_resolution_clock::now();
    auto durationEnd = duration_cast<microseconds>(end - start);

    cout << setw(10) << size
         << setw(50) << durationHead.count()
         << setw(50) << durationEnd.count() << endl;
}

int main()
{
    cout << setw(10) << "Size"
         << setw(50) << "InsertToHead (microseconds)"
         << setw(50) << "InsertToEnd (microseconds)" << endl;

    for (int size = 100000; size <= 1000000; size += 100000)
    {
        testInsertPerformance(size, 1000);
    }

    system("pause");
    return 0;
}