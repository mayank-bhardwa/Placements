#include <iostream>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

void solve()
{
	int x,m,d;
	cin>>x>>m>>d;
	cout<<min(x*m,x+d);
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