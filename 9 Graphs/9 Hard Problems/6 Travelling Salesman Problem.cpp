#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
int TSP(int adj[4][4],int n,int src)
{
	vector<int> vtx;
	
	for(int i=0;i<n;i++)
	if(i!=src)
	vtx.push_back(i);
	
	int minpath=INT_MAX;
	
	do
	{
		int currpath=0;
		
		int k=src;
		for(int i=0;i<vtx.size();i++)
		{
			currpath+=adj[vtx[i]][k];
			k=vtx[i];
		}
		currpath+=adj[k][src];
		
		minpath=min(minpath,currpath);
		
	}while(next_permutation(vtx.begin(),vtx.end()));
	
	return minpath;
}
signed main()
{
	int adj[4][4] = { { 0, 10, 15, 20 },
                      { 10, 0, 35, 25 },
                      { 15, 35, 0, 30 },
                      { 20, 25, 30, 0 } };
                       
    int n=4;
    
    cout<< TSP(adj,n,0);
    
    return 0;
}
