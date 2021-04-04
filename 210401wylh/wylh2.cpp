/*
 * 怪物击杀
 * 给定 1 个，固定大小的方形棋盘（1000 * 1000），在棋盘的任意一个位置可能会有怪物
 * 你有两种技能可以释放，一种是横向，竖向或者两种斜向之一，范围内的怪物会被全部击杀
 * 第二种是选择一个怪物，以这个怪物为中心的方形范围内的所有怪物被击杀
 * 要求给出在释放一个技能的前提下最大怪物击杀数量
 * 输入描述：
 * 第一行输入第二个技能的半径 N 
 * 第二行输入怪物的数量 num 
 * 第三行一次指定怪物的 x 和 y 坐标
 * 输出描述：
 * 最大可能击杀数
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    int x;
    int y;
} nodes[200];

int axis[300][300] = { 0 };

int main()
{
    int N;
    cin >> N;

    int num;
    cin >> num;
    int tmpx, tmpy;
    for (int i = 0; i < num; i++)
    {
        //cin >> nodes[i].x >> nodes[i].y;
        cin >> tmpx >> tmpy;
        axis[tmpx - 1][tmpy - 1]++;
    }

    int max = 0;
    for (int i = 0; i < 300; i++)
    {
        int sum = 0;
        for (int j = 0; j < 300; j++)
        {
            sum += axis[i][j];
        }
        max = std::max(max, sum);
    }

    for (int i = 0; i < 300; i++)
    {
        int sum = 0;
        for (int j = 0; j < 300; j++)
        {
            sum += axis[j][i];
        }
        max = std::max(max, sum);
    }

    for (int i = 0; i < 300; i++)
    {
        int sum = 0;
        int j = 0;
        int k = i;
        while (k < 300 && j < 300 && k > -1 && j > -1)
        {
            sum += axis[k][j];
            k++;
            j++;
        }
        max = std::max(max, sum);
    }

    for (int i = 0; i < 300; i++)
    {
        int sum = 0;
        int j = 0;
        int k = i;
        while (k < 300 && j < 300 && k > -1 && j > -1)
        {
            sum += axis[k][j];
            k--;
            j++;
        }
        max = std::max(max, sum);
    }

    for (int i = 0; i < 300; i++)
    {
        int sum = 0;
        int j = 299;
        int k = i;
        while (k < 300 && j < 300 && k > -1 && j > -1)
        {
            sum += axis[k][j];
            k++;
            j--;
        }
        max = std::max(max, sum);
    }

    for (int i = 0; i < 300; i++)
    {
        int sum = 0;
        int j = 299;
        int k = i;
        while (k < 300 && j < 300 && k > -1 && j > -1)
        {
            sum += axis[k][j];
            k--;
            j--;
        }
        max = std::max(max, sum);
    }

    for (int i = 0; i < 300; i++)
    {
        for (int j = 0; j < 300; j++)
        {
            if (axis[i][j] > 0)
            {
                int sum = 0;
                int beginx = 0 > i - N ? 0 : i - N;
                int endx = 299 < i + N ? 299 : i + N;
                int beginy = 0 > j - N ? 0 : j - N;
                int endy = 299 < j + N ? 299 : j + N;
                for (int k = beginx; k < endx + 1; k++)
                {
                    for (int l = beginy; l < endy + 1; l++)
                    {
                        sum += axis[k][l];
                    }
                }

                max = std::max(max, sum);
            }

        }
    }

    cout << max;
    return 0;
}