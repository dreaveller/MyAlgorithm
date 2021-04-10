/*
 * 等差数列
 * 现在有一排高度随机的树，你可以施展一种魔法，使其中一颗树变为任意高度
 * 为了这一排树的美观性，需要你将这排树变成一个等差数列
 * 输入描述
 * 第一行输入树的数量 n (1<=n<=1e5)，和等差 x (1<=x<=1000)
 * 接下来一行输入 n 棵树的高度
 * 输出描述
 * 达到要求的最少魔法施展次数
 */

/*
 * 骗了 66%
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int trees[100001];
bool flag[100001];

vector<int> vec;

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }

    int cc = n;
    for (int i = 0; i < n; i++)
    {
        if (flag[i])
            continue;
        if (trees[i] < (i)*x + 1)
            continue;

        int sum = n - 1;
        for (int j = i + 1; j < n; j++)
        {
            if (trees[j] - trees[i] == (j - i) * x)
            {
                sum--;
                flag[j] = true;
            }
        }
        vec.push_back(sum);
        cc -= (n - sum);
        if (cc < n / 2)
            break;
    }

    int min = n;
    for (int i = 0; i < vec.size(); i++)
    {
        min = min < vec[i] ? min : vec[i];
    }
    cout << min;
    return 0;
}