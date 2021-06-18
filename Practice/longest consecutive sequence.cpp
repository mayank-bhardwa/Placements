#include <bits/stdc++.h>
using namespace std;
// 100,4,200,1,3,2
int lcs(vector<int> &a)
{
    unordered_set<int> set;

    for (auto i : a)
    {
        set.emplace(i);
    }
    int mx = -1, c, n;
    for (int i : set)
    {
        if (set.find(i - 1) == set.end())
        {
            c = 1;
            n = i;
            while (set.find(n + 1) != set.end())
            {
                set.erase(n);
                c++;
                n++;
            }

            mx = max(mx, c);
        }
    }
    return mx;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    cout << lcs(a);

    return 0;
}