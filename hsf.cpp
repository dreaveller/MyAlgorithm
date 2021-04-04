#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> vec;
stack<int> sta;

void backtracking(int start, int len, vector<int>& vec)
{
    if (len <= 0)
    {
        return;
    }
    
    for (int i = start; i < len + start; i++)
    {
        sta.push(vec[i]);
        backtracking(i + 1, len - 1, vec);
        sta.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        vec.push_back(tmp);
    }
    backtracking(0, 2, vec);
}