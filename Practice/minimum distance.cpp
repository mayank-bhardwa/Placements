#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	int n, x;
	cin >> n;
	unordered_map<int, vector<int>> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		mp[x].emplace_back(i);
	}
	int mn = INT16_MAX, d=-1;
	for (auto i : mp)
	{
		if (i.second.size() > 1)
			for (int j = 1; j < i.second.size(); j++)
			{
				d = i.second[j] - i.second[j - 1];
				mn = min(mn, d);
			}
	}
	cout << min(mn,d);
	return 0;
}