#include <iostream>
#include <vector>
#define deb(x) cout<<#x<<" "<<x<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

void solve()
{
	long long n, k, f;
	cin >> n >> k >> f;
	long long s, e;
	long long c=0;
	for (long long i = 0; i < n; ++i)
	{
		cin >> s >> e;
		c+= e-s;
	}

	c = f-c;

	if(c >= k)cout<<"YES";
	else cout<<"NO";
}

int main(int argc, char const *argv[])
{
	fast;
#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
#endif
	long long t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}