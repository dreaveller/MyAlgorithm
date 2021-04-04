#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> vec;
vector<int> vec1;

struct node
{
    int index;
    int num;
    int ans;
} nodes[int(1e9 + 10)];

void swap(int a, int b)
{
    int tmp;
    tmp = vec1[a];
    vec1[a] = vec1[b];
    vec1[b] = tmp;
}

int main()
{
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        vec1.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (j == 0)
                continue;
            if (vec1[j] > vec1[j - 1])
            {
                swap(j, j - 1);
            }
        }
        vector<int> vect = vec1;
        vect.resize(i + 1);
        vec.push_back(vect);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int tmpl;
        cin >> tmpl;
        cout << vec[tmpl - 1][1] << endl;
    }
}