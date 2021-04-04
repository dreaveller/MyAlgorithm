#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
const int maxn = 10000;
int a[maxn];
struct node
{
    int v;
    node *l, *r;
    node(int x)
    {
        v = x;
        l = NULL, r = NULL;
    }
};

void dfs(node *rot)
{
    if (rot->l == NULL && rot->r == NULL)
    {
        cout << rot->v;
        return;
    }
    cout << "(";
    dfs(rot->l);
    cout << ',';
    dfs(rot->r);
    cout << ")";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<node *> a, b;
    for (int i = 1; i <= n; ++i)
    {
        a.push_back(new node(i));
    }
    while (int(a.size()) > 1)
    {
        int l = 0, r = a.size() - 1;

        while (l < r)
        {
            node *cur = new node(max(a[l]->v, a[r]->v));
            cur->l = a[l];
            cur->r = a[r];
            ++l, --r;
            b.push_back(cur);
        }
        swap(a, b);
        b.clear();
    }
    dfs(a[0]);
    cout << endl;
    return 0;
}
