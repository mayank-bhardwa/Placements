#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int pairs(int k, vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> freq;
    int c = 0, t1, t2;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        t2 = k + arr[i];
        if (freq.find(t2) != freq.end())
        {
            c++;
        }
        freq.insert(arr[i]);
    }

    return c;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << pairs(k, arr);
    return 0;
}