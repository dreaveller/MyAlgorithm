/*
 * 输入两个二进制字符串以;隔开，输出乘积
 * 例如10;10 输出100
 */

/*
 * 本地 MSVC 和 GCC 都可以 AC。OJ 连测试用例都过不了，估计应该是 clang 。
 * 问题很大
 */

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#define NULL 0

char c1[100000] = { NULL };
char c2[100000] = { NULL };
int res[200000] = { 0 };

int main()
{
    int i = 0;
    while ((cin >> c1[i]))
    {
        if (c1[i] == ';')
            break;
        i++;
    }
    int len1 = i;
    i = 0;
    while (scanf("%c", &c2[i]))
    {
        if (c2[i] == '\n')
            break;
        i++;
    }
    int len2 = i;

    for (int j = len2 - 1; j > -1; j--)
    {
        if (c2[j] == '1')
        {
            for (int k = len1 - 1; k > -1; k--)
            {
                res[len2 - 1 - j + len1 - 1 - k] += (((int)c1[k]) - 48);
            }
        }
    }

    for (int j = 0;j < 200000 - 1; j++)
    {
        res[j + 1] = res[j + 1] + res[j] / 2;
        res[j] = res[j] % 2;
    }

    bool flag = false;
    for (int j = 200000; j > -1; j--)
    {
        if (res[j] == 1) flag = true;
        if (flag) cout << res[j];
    }
}