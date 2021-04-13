#include <iostream>
#include <map>
using namespace std;

const int maxn = 1e5 + 10;
int x, n;
int a[maxn], b[maxn], c[maxn];
map<int, int> mp[1010];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    if (x == 0)
    {
        map<int, int> mpp;
        int ans = 1e9;
        for (int i = 1; i <= n; ++i)
            mpp[a[i]]++;
        for (auto cur : mpp)
        {
            ans = min(ans, n - cur.second);
        }
        cout << ans << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        mp[a[i] % x][i - a[i] / x]++;
    }

    int ans = 1e9 + 10;
    for (int i = 0; i <= 1000; ++i)
    {
        for (auto cur : mp[i])
        {
            ans = min(ans, n - cur.second);
        }
    }
    cout << ans << endl;

    return 0;
}