#include <iostream>
#include <vector>
#define deb(x) cout<<#x<<" "<<x<<"\n"
#define ll long long
using namespace std;

int main()
{
	ll n, t;
	cin >> n >> t;
	vector<int> a(n - 1);
	for (auto &i : a)
		cin >> i;


	bool status = false;
	for (int i = 1; i < t;)
	{
		if (a[i - 1] + i == t)
		{
			status = true;
			break;
		}
		i += a[i - 1];
	}

	if (status) cout << "Yes";
	else cout << "No";

	return 0;
}