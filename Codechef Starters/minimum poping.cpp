#include <iostream>
#include <vector>
#define deb(x) cout << #x << " " << x << "\n"
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);
using namespace std;

bool all(vector<int> freq)
{
	for (auto i : freq)
		if (i == 0)
			return false;

	return true;
}

int func(vector<int> q, int f, int l, int pop_count, vector<int> freq)
{
	if (l == f || all(freq))
		return pop_count;

	freq[f]++;
	int x = func(q, f + 1, l, pop_count + 1, freq);
	freq[f]--;

	freq[l]++;
	int y = func(q, f, l - 1, pop_count + 1, freq);

	return min(x, y);
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> q(m);

	for (int i = 0; i < m; ++i)
	{
		cin >> q[i];
	}
	vector<int> f(m, 0);
	cout << func(q, 0, m - 1, 0, f);
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