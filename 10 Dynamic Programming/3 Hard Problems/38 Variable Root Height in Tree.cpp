#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100;

int in[MAX_NODES];

int out[MAX_NODES];

void dfs1(vector<int> v[] , int u , int parent)
{
	in[u] = 0;
	
	for(int child : v[u])
	{
		if(child == parent)
		continue;
		
		dfs1(v , child , u);

		in[u] = max(in[u], 1 + in[child]);
	}
}

void dfs2(vector<int> v[] , int u , int parent)
{
	int mx1 = -1 , mx2 = -1;

	for(int child : v[u])
	{
		if (child == parent) 
		continue; 

		if (in[child] >= mx1)
		{
			mx2 = mx1;
		
			mx1 = in[child];
		}

		else if(in[child] > mx2)
		mx2 = in[child];
	}

	for(int child : v[u])
	{
		if (child == parent) 
		continue; 

		int longest = mx1; 

		if (mx1 == in[child])
		longest = mx2;
			
		out[child] = 1 + max(out[u] , 1 + longest);

		dfs2(v , child , u);
	}
}

void printHeights(vector<int> v[] , int n)
{
	dfs1(v , 1 , 0);

	dfs2(v , 1 , 0);

	for (int i = 1 ; i <= n ; i++)
	cout << "The maximum height when node " << i << " is considered as root" << " is " << max(in[i], out[i]) << "\n";
}

int main()
{
	int n = 11;
	
	vector<int> v[n + 1];

	v[1].push_back(2)  , v[2].push_back(1);
	v[1].push_back(3)  , v[3].push_back(1);
	v[1].push_back(4)  , v[4].push_back(1);
	v[2].push_back(5)  , v[5].push_back(2);
	v[2].push_back(6)  , v[6].push_back(2);
	v[3].push_back(7)  , v[7].push_back(3);
	v[7].push_back(10) , v[10].push_back(7);
	v[7].push_back(11) , v[11].push_back(7);
	v[4].push_back(8)  , v[8].push_back(4);
	v[4].push_back(9)  , v[9].push_back(4);
	
	printHeights(v , n);

	return 0;
}

