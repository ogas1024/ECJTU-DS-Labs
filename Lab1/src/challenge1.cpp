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

    // dp[i][j] 表示当可选的数字范围是 [i, j] 时，先手能取得的最大分数
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prefixSum(2 * n + 1, 0); // 前缀和用于快速计算区间和

    // 计算前缀和
    for (int i = 0; i < 2 * n; i++)
        prefixSum[i + 1] = prefixSum[i] + nums[i % n];

    // 初始化当只有一个数字时
    for (int i = 0; i < n; i++)
        dp[i][i] = nums[i];

    // 处理长度大于1的区间
    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = (i + length) % n; // j 是环形链表中的尾部
            int total = prefixSum[j + 1] - prefixSum[i + 1];

            dp[i][j] = max(
                nums[i] + (total - dp[(i + 1) % n][j]),    // 选择左边的数字
                nums[j] + (total - dp[i][(j - 1 + n) % n]) // 选择右边的数字
            );
        }
    }

    return dp[0][n - 1]; // 返回全局的最优解
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

    // 转换为数组
    vector<int> nums = list.toArray();

    // 计算最大得分
    int result = maxScore(nums);
    cout << "最大得分为: " << result << endl;

    system("pause");

    return 0;
}
