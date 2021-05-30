#include <iostream>
#include <vector>
#include <algorithm>
#define deb(x) cout << #x << " " << x << "\n"
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);
using namespace std;

void solve()
{
	int n, k, f;
	cin >> n >> k >> f;
	vector<pair<int, int>> invi(n);
	int gap = 0;
	vector<int> c(f, 1);

	for (int i = 0; i < n; ++i)
	{
		cin >> invi[i].first >> invi[i].second;
		for (int j = invi[i].first; j < invi[i].second; j++)
		{
			c[j] = 0;
		}
	}

	for (auto i : c)
		gap += i;
	if (gap >= k)
		cout << "YES";
	else
		cout << "NO";
}

int main(int argc, char const *argv[])
{
	fast;
#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}