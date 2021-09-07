/*
	Program to find minimum distance between two nodes
*/
#include <iostream>
#include <vector>
using namespace std;

int graph[] = {
	{0, 8, 9},
	{8, 0, 7},
	{9, 7, 0}
};

void dfs(int start)
{
	vector<bool> visited(3, false);
	for(int i=0;i<3;i++)
	{
		if(!visited[i])
		{
			goDeep(visited,i);
		}
	}
}

void goDeep(vector<bool> visited,int i)
{
	visited[i] = true;
	
}


int main(int argc, char const *argv[])
{

	return 0;
}