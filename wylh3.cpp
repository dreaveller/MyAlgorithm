/*
 * 接水果游戏
 * 在市面上的常见接水果游戏中，玩家总是要控制一个篮子，左右移动篮子以接住上方掉落下来的水果，当丢失的水果达到一定数量后游戏失败
 * 本题目给定篮子的初始横坐标 x，水平移动速度 v，和丢失 m 个水果后游戏失败。给定所有水果的 x ， y 坐标和接住后的得分 p，水果以 1m/s 的速度向下移动。
 * 输入描述：
 * 第一行输入篮子横坐标 x，水平移动速度 v，造成失败的丢失水果数量 m 
 * 接下来一行输入水果的总数量 n
 * 接下来 n 行输入水果的 x 坐标， y 坐标和分数 p
 * 输出描述：
 * 输出在游戏不失败的情况下的最高得分
 */

/*
 * 目前我只实现了不加 m 限制条件的动态规划解法
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct fruit
{
    int x;
    int y;
    int p;
} fruits[1000];

int dp[1000][1000] = {0};
bool flag[1000][1000] = {false};

bool cmp(fruit a, fruit b)
{
    return a.y < b.y;
}

int maxx(int index, int offset, int c)
{
    int max = 0;
    int begin = (0 > index - offset ? 0 : index - offset);
    int end = (999 < index + offset ? 999 : index + offset);
    for (int i = begin; i <= end; i++)
    {
        if (flag[c][i])
        {
            max = std::max(dp[c][i], max);
        }
    }
    return max;
}

int main()
{
    int x, v, m;
    cin >> x >> v >> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i].x >> fruits[i].y >> fruits[i].p;
    }
    sort(fruits, fruits + n, cmp);

    for (int i = 0; i < 1000; i++)
    {
        for (int k = (0 > x - v * i ? 0 : x - v * i); k <= (999 < x + v * i ? 999 : x + v * i); k++)
        {
            flag[i][k] = true;
        }
    }

    for (int i = 1; i < 1000; i++) // 秒数
    {
        for (int k = 0; k < 1000; k++) // x
        {
            if (flag[i][k])
            {
                dp[i][k] = maxx(k, v, i - 1);
            }
        }
        for (int j = 0; j < n; j++) // 节点
        {
            if (fruits[j].y == i && flag[i][fruits[j].x])
            {
                dp[i][fruits[j].x] = maxx(fruits[j].x, v, i - 1) + fruits[j].p;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < 1000; i++)
    {
        max = std::max(max, dp[999][i]);
    }

    cout << max;
    cin >> max;
}