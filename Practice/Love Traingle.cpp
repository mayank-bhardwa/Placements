#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<"\n"
#define fast ios_base::sync_with_stdio(NULL);cin.tie(0);
#define vi vector<int>
#define ui unordered_map<int,int>
#define oi ordered_map<int,int>
#define fo(i,n) for(int i=0;i<n;i++)
#define rfo(i,n) for(int i=n;i>=0;i--)
unsigned const mod = 1e9 + 7;
using namespace std;

vector<int> g;

int main(int argc, char const *argv[])
{
	fast;
#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
#endif
	int t, m;
	cin >> t;
	g = vector<int>(t + 1);
	fo(i, t) {
		cin >> m;
		g[i + 1] = m;
	}
	bool status = false;
	for (int i = 1; i <= t; i++)
	{
		if(g[g[g[i]]]==i){
			status=true;
			break;
		}
	}

	if (status)cout << "True";
	else cout << "False";

	return 0;
}