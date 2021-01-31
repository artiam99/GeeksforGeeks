#include<bits/stdc++.h>
using namespace std;
#define int long long
bool DFS(vector<vector<bool>> &adj,int u,int n,vector<int> &color,int cr)
{
	if(color[u] != -1)
	return (color[u] != cr);
	
	color[u]=cr;
	
	for(int i=0;i<n;i++)
	if(adj[u][i] && !DFS(adj,i,n,color,1-cr))
	return false;
	
	return true;
}
bool isBipartite(vector<vector<bool>> &adj,int n)
{
	vector<int> color(n,-1);
	
	for(int i=0;i<n;i++)
	if(color[i] == -1 && !DFS(adj,i,n,color,1))
	return false;
	
	return true;
}
bool TwoClique(vector<vector<bool>> &adj,int n)
{
	vector<vector<bool>> comp=adj;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		if(i!=j)
		comp[i][j]=!comp[i][j];
	}
	
	return isBipartite(comp,n);
}
signed main()
{
	vector<vector<bool>> adj = { {0, 1, 1, 0, 0},
            			         {1, 0, 1, 1, 0},
           			             {1, 1, 0, 0, 0},
                  			     {0, 1, 0, 0, 1},
                  		         {0, 0, 0, 1, 0} };
    int n=adj.size();
    
    if(!TwoClique(adj,n))
    cout<< "Possible" <<endl;
    else
    cout<< "Impossible" <<endl;
	
	return 0;
}
