#include <iostream>
#include <vector>
#include <algorithm>
#include "CircularLinkList.h"

using namespace std;

int maxScore(const vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    // dp[i][j] ��ʾ����ѡ�����ַ�Χ�� [i, j] ʱ��������ȡ�õ�������
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prefixSum(2 * n + 1, 0); // ǰ׺�����ڿ��ټ��������

    // ����ǰ׺��
    for (int i = 0; i < 2 * n; i++)
        prefixSum[i + 1] = prefixSum[i] + nums[i % n];

    // ��ʼ����ֻ��һ������ʱ
    for (int i = 0; i < n; i++)
        dp[i][i] = nums[i];

    // �����ȴ���1������
    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = (i + length) % n; // j �ǻ��������е�β��
            int total = prefixSum[j + 1] - prefixSum[i + 1];

            dp[i][j] = max(
                nums[i] + (total - dp[(i + 1) % n][j]),    // ѡ����ߵ�����
                nums[j] + (total - dp[i][(j - 1 + n) % n]) // ѡ���ұߵ�����
            );
        }
    }

    return dp[0][n - 1]; // ����ȫ�ֵ����Ž�
}

int main()
{
    CircularLinkList<int> list;
    list.insertToEnd(1);
    list.insertToEnd(5);
    list.insertToEnd(3);
    list.insertToEnd(7);
    list.insertToEnd(2);

    list.display();

    // ת��Ϊ����
    vector<int> nums = list.toArray();

    // �������÷�
    int result = maxScore(nums);
    cout << "���÷�Ϊ: " << result << endl;

    system("pause");

    return 0;
}
