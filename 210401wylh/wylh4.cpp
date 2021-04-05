/*
 * 电路模拟
 * 在电路中总共存在 5 种元件，他们的功能分别如下：
 * A 元件，持续不断的向外提供电力，有一个出口
 * B 元件，控制一个开关，当开关处于关闭状态时，电流无法通过，反之电流可以通过，有一个进口和一个出口
 * C 元件，电流总是可以通过，有一个进口和四个出口
 * D 元件，维持一个计数器，当收到一个电流从无到有的脉冲时计数器值 +1，电流总是可以通过，有一个进口和一个出口
 * E 元件，收到一个电流从无到有的脉冲时，此时若该元件出口无电流则改变状态输出电流，否则改变状态关闭电流，有一个出口和一个进口
 * 对于每一个进口，该进口只能连接 0 或 1 个出口。对于每一个出口，该出口只能连接 0 或 1 个进口
 * 在完成电路的连接之后，立即判断一次状态的变化，例如一个 A 元件与 一个 D 元件相连，则电路完成后 D 元件的计数即 +1
 * 对于每一个开关，按动之后总是可能会对电路目前的状态造成改变，进而影响到 D 元件的计数
 * 输入描述：
 * 第一行输入电路总的元件个数 t
 * 接下来一行 t 个字符指定每个元件的种类
 * 接下来一行输入电路中的连线数 M
 * 接下来一行依次输入连接的元件，例如 1 2 3 4 则为第 1 个元件的出口与第 2 个元件的进口相连，第 3 个元件的出口与第 4 个元件的进口相连
 * 接下来一行输入按下开关的次数 S
 * 接下来一行输入每次按的元件编号，如果该编号的元件不是 B 元件，则什么都不做
 * 输出描述：
 * 一行输出所有 D 元件的计数
 */

/*
 * 笔试现场没写出来，笔试完删了一个 if 测试用例就过了，现在没有完备的测试数据，无法确定程序是否正确
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
    char ttype;
    int charge = 0;
    int bstatus = 0;
    int cstatus = 0;
    int count = 0;
    node *next[4] = {NULL};
} nodes[256];

vector<node> vec;
queue<node *> que;
queue<node *> que2;

void check(node *n)
{
    for (int i = 0; i < 4; i++)
    {
        if (n->next[i] != NULL)
        {
            if (n->next[i]->ttype == 'B')
            {
                if (n->next[i]->charge == 1)
                {
                    n->next[i]->charge = 0;
                }
                n->next[i]->charge = 1;
                n->next[i]->bstatus = 1;
                if (n->next[i]->charge == 1)
                {
                    que.push(n->next[i]);
                }
            }
            if (n->next[i]->ttype == 'C')
            {
                n->next[i]->charge = 1;
            }
            if (n->next[i]->ttype == 'D')
            {
                if (n->next[i]->charge == 0)
                {
                    n->next[i]->count++;
                                }
                n->next[i]->charge = 1;
                que.push(n->next[i]);
            }
            if (n->next[i]->ttype == 'E')
            {
                n->next[i]->charge = 1;
                que.push(n->next[i]);
            }
        }
    }
}

void cc(node *n)
{
    for (int i = 0; i < 4; i++)
    {
        if (n->next[i] != NULL)
        {
            if (n->next[i]->ttype != 'B')
            {
                n->next[i]->charge = 0;
                que2.push(n->next[i]);
            }
        }
    }
}

int main()
{
    int nid;
    cin >> nid;
    for (int i = 0; i < nid; i++)
    {
        char ttype;
        cin >> ttype;
        nodes[i].ttype = ttype;
        if (ttype == 'A')
        {
            nodes[i].charge = 1;
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        int j = 0;
        while (nodes[a - 1].next[j] != NULL)
            j++;
        nodes[a - 1].next[j] = &nodes[b - 1];
    }

    for (int i = 0; i < nid; i++)
    {
        if (nodes[i].ttype == 'A')
        {
            vec.push_back(nodes[i]);
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].next[0] != NULL)
        {
            if (vec[i].next[0]->ttype == 'B')
            {
                vec[i].next[0]->bstatus = 1;
                vec[i].next[0]->charge = 1;
                que.push(vec[i].next[0]);
            }
            if (vec[i].next[0]->ttype = 'C')
            {
                vec[i].next[0]->charge = 1;
            }
            if (vec[i].next[0]->ttype == 'D')
            {
                vec[i].next[0]->count++;
                vec[i].next[0]->charge = 1;
                que.push(vec[i].next[0]);
            }
            if (vec[i].next[0]->ttype == 'E')
            {
                vec[i].next[0]->charge = 1;
                que.push(vec[i].next[0]);
            }
        }
    }

    while (!que.empty())
    {
        node *n = que.front();
        que.pop();
        if (n->charge == 1)
        {
            check(n);
        }
    }

    int S;
    cin >> S;
    for (int i = 0; i < S; i++)
    {
        int tmp;
        cin >> tmp;
        node *n = &nodes[tmp - 1];

        if (n->ttype != 'C')
            continue;
        else
        {
            if (n->next[0] == NULL)
            {
                continue;
            }
            if (n->charge == 1)
            {
                if (n->cstatus == 1)
                {
                    n->cstatus = 0;
                    n->next[0]->charge = 0;
                    que2.push(n->next[0]);
                    while (!que2.empty())
                    {
                        node *n = que2.front();
                        que2.pop();
                        cc(n);
                    }
                }
                else if (n->cstatus == 0)
                {
                    n->cstatus = 1;
                    n->next[0]->charge = 1;
                    que.push(n->next[0]);
                    while (!que.empty())
                    {
                        node *n = que.front();
                        que.pop();
                        if (n->charge == 1)
                        {
                            check(n);
                        }
                    }
                }
            }
            else if (n->charge == 0)
            {
                n->cstatus = 1;
            }
        }
    }

    for (int i = 0; i < nid; i++)
    {
        if (nodes[i].ttype == 'D')
        {
            cout << nodes[i].count << " ";
        }
    }
}