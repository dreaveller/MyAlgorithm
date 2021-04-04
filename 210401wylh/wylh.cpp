/*
 * 同花顺
 * 从两副扑克牌中随机选择 27 张牌
 * 相同花色的五张递增序列称为同花顺
 * 特别的，A 既可以参与 10,J,Q,K,A 的同花顺，也可以参与 A,2,3,4,5 的同花顺，大王，小王不参与同花顺
 * 另外，假如拥有 A,2,3,4,5 的相同花色各两张，则不算作两个同花顺，但是两张同色 A 与同色 2,3,4,5 各一张算作两个同花顺，以此类推
 * 输入描述：
 * 共 27 行
 * 每行第一个数字指定牌的大小，第二个数字指定牌的颜色
 * J 为 11，Q 为 12，K 为 13，A 为14 ，小王为 15，大王为 16，颜色则使用 1,2,3,4 指定
 * 输出描述：
 * 拥有的同花顺个数
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int num;
    int color;
} nodes[27];

vector<node> vec;

bool cmp(node a, node b) {
    return a.num < b.num;
}

int main()
{
    for (int i = 0; i < 27; i++)
    {
        cin >> nodes[i].num >> nodes[i].color;
    }

    sort(nodes, nodes + 27, cmp);

    for (int i = 0; i < 27; i++)
    {
        if (nodes[i].num == 14)
        {
            vec.push_back(nodes[i]);
        }
    }
    for (int i = 0; i < 27; i++)
    {
        if (nodes[i].num < 15)
        {
            vec.push_back(nodes[i]);
        }
    }
    
    

    int sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].num > 10) continue;
        
        int level = vec[i].num % 13;
        int color = vec[i].color;
        int count = 1;
        int j = i + 1;
        while (j < vec.size())
        {
            if (vec[j].num == level + 1 && vec[j].color == color)
            {
                count++;
                level++;
            }
            j++;
            if (count == 5)
            {
                sum++;
                break;
            }
        }
    }
    cout << sum;

    return 0;
}