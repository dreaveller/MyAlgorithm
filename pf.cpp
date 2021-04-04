#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
struct node
{
	int id;
	int r;
	int ans = -1;
} r[maxn];

bool cmp1(const node &a, const node &b)
{
	return a.r < b.r;
}
bool cmp2(const node &a, const node &b)
{
	return a.id < b.id;
}

int main()
{
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		r[i].id = i;
		cin >> r[i].r;
	}
	sort(r + 1, r + 1 + m, cmp1);
	int Max = -1, Max2 = -1;

	int id = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] >= Max)
		{
			Max2 = Max;
			Max = a[i];
		}
		else if (a[i] >= Max2)
			Max2 = a[i];
		if (r[id].r == i)
		{
			r[id].ans = Max2;
			++id;
		}
	}
	sort(r + 1, r + 1 + m, cmp2);
	for (int i = 1; i <= m; ++i)
	{
		cout << r[i].ans << endl;
	}
	return 0;
}
