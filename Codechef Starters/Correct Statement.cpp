#include <iostream>
#include <vector>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int group(char i)
{
	return i >= 'a' and i <= 'm' ? 1 : i >= 'N' and i <= 'Z' ? 2 : 3;
}

void solve()
{
	int k;
	bool status = true;
	cin >> k;
	vector<string> s(k);
	for (int i = 0; i < k; ++i)
	{
		cin>>s[i];
	}

	int g=1;
	for(auto i : s)
	{
		g =  group(i[0]);
		for(auto k : i)
		{
			if(group(k) != g)
			{
				cout<<"NO";
				return;
			}
		}
		if(g==3){
			cout<<"NO";
			return;
		}
	}

	cout<<"YES";
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