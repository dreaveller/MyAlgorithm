/*
 * 操作系统任务调度
 * 现在有一系列任务，每个任务都有准备时间和执行时间
 * 处理机可以同时处理多个任务的准备时间，但是只能同时处理一个任务的执行时间
 * 输入描述
 * 第一行输入一个数字 n 表示任务数量
 * 接下来 n 行每行输入任务的准备时间和执行时间
 * 输出描述
 * 完成所有任务的最早时间
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct task
{
    int rtime;
    int etime;
} tasks[50001];

bool cmp(task a, task b);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].rtime >> tasks[i].etime;
    }
    sort(tasks, tasks + n, cmp);

    int index = tasks[0].rtime;
    for (int i = 0; i < n - 1; i++)
    {
        index += tasks[i].etime;
        if (index < tasks[i + 1].rtime)
        {
            index = tasks[i + 1].rtime;
        }
    }
    index += tasks[n - 1].etime;
    cout << index;
}

bool cmp(task a, task b)
{
    return a.rtime < b.rtime;
}