#include<bits/stdc++.h>
using namespace std;
#define int long long
void GoodNodes(vector<vector<int>> &adj,int n)
{
	set<int> vtx;
	
	for(int i=0;i<n;i++)
	vtx.insert(i);
	
	while(vtx.size())
	{
		bool flag=1;
		for(auto i:vtx)
		{
			unordered_set<int> color;
			for(auto j:vtx)
			if(i!=j)
			color.insert(adj[i][j]);
			
			if(color.size()==1)
			{
				flag=0;
				vtx.erase(i);
				break;
			}
		}
		if(flag)
		break;
	}
	for(auto i:vtx)
	cout<<i+1<<" ";
	cout<<endl;
}
signed main()
{
	vector<vector<int>> adj= { {0, 9, 2, 4, 7, 8},
    						   {9, 0, 9, 9, 7, 9},
      						   {2, 9, 0, 3, 7, 6},
   							   {4, 9, 3, 0, 7, 1},
      						   {7, 7, 7, 7, 0, 7},
      						   {8, 9, 6, 1, 7, 0} };
	int n=adj.size();
	
	GoodNodes(adj,n);
	
	return 0;
}
