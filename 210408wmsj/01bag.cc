/*
 * 01背包
 * 奇怪的实现思路，用二维 flag 数组表示背包容量为 i 的情况下是否选择 j 物品
 * 造成了可能有多种选择的问题
 * 最终 AC80%
 */

/*
 * 看了下自己错的原因，把容量循环套在了物品循环的外层，
 * 虽然 flag 数组维持了特定容量情况下的物品选择情况，但是也有可能出现相同容量多个选择的情况
 * DP 要求一定是无后效性的，看了网上的实现，是要把物品循环套在容量循环外层
 * 01背包虽然是经典动态规划问题，也是动态规划入门必学的问题，但是可能我的学习路线与常人不同吧，也没有刻意去记01背包的实现，所以出错
 */

#include <iostream>
using namespace std;

struct node
{
    int wei;
    int value;
    bool flag;
} nodes[10000];

int bag[10000];
bool flag[10000][10000];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].wei;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].value;
    }

    bag[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        int index = -1;
        int cc;
        for (int j = 0; j < n; j++)
        {
            if (i - nodes[j].wei >= 0)
            {
                if (bag[i] < bag[i - nodes[j].wei] + nodes[j].value && !flag[i - nodes[j].wei][j])
                {
                    bag[i] = bag[i - nodes[j].wei] + nodes[j].value;
                    index = j;
                    cc = i - nodes[j].wei;
                }
            }
        }
        for (int j = 0; j < 10000; j++)
        {
            flag[i][j] = flag[i - 1][j];
        }
        if (index == -1)
        {
            continue;
        }
        for (int j = 0; j < 10000; j++)
        {
            flag[i][j] = flag[cc][j];
        }

        flag[i][index] = true;
    }
    cout << bag[m];
    return 0;
}