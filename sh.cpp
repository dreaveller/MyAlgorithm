#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> vec;
vector<int> vec2;

vector<vector<bool>> vecb;
vector<bool> vecb1;

queue<int> que;

void bfs(int i)
{
    que.push(i);
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[i][j] == 1)
        {
            que.push(j);
        }
    }
    que.pop();
    
}

int main() 
{
    int n;
    int tmp;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        vector<int> v1;
        vector<bool> v2;
        vec.push_back(v1);
        vecb1.push_back(false);
        for (int j = 0; j < n; j ++)
        {
            cin >> tmp;
            vec[i].push_back(tmp);
        }
    }

    que.push(0);
    for (int k = 0; k < vec.size(); k++)
    {
        if (vecb1[k])
        {
            continue;
        }
        
        while (!que.empty())
        {
            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[que.front()][i] == 1)
                {
                    que.push(i);
                    if (vecb1[i] == false)
                    {
                        vecb1[i] = true;
                    }else if (vecb1[i] == true)
                    {
                        cout << "Loop";
                        return 1;
                    }
                    
                }
            }
            que.pop();
        }
    }
    cout << "No Loop";
    
}
