#include <iostream>
using namespace std;

int main()
{
    string s = "hello";
    string rev = string(s.rbegin(), s.rend());
    cout << s.substr(2, 5) << " " << rev;
    cout << __cplusplus;
    return 0;
}