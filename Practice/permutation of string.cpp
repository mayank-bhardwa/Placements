#include <iostream>
#include <vector>
using namespace std;

void Permutations(string s,string k)
{
	if(s.size() == k.size()){
		cout<<k<<endl;
		return;
	}

	for(auto i: s)
	{
		Permutations(s,k+i);
	}
}

int main()
{
	freopen("input","r",stdin);
	string s;
	cin>>s;
	Permutations(s,"");
	return 0;
}