#include <iostream>
#include <vector>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> l(k);
	vector<int> freq(n + m + 1, 0);

	for (int i = 0; i < k; i++)
	{
		cin >> l[i];
		freq[l[i]]++;
	}
	vector<int> res;
	int c = 0;
	for (int i = 1; i <= n; i++)
	{
		if (freq[i] > 1)
		{
			c++;
			res.emplace_back(i);
		}
	}
	cout<<c<<" ";
	for(auto i: res)cout<<i<<" ";
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