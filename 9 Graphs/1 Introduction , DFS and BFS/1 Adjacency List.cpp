#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void printGraph(vector<int> adj[],int V)
{
	for(int i=0;i<V;i++)
	{
		cout<<i;
		for(int j=0;j<adj[i].size();j++)
		{
			if(j<adj[i].size())
			cout<<"->";
			cout<<adj[i][j];
		}
		cout<<endl;
	}
}
signed main()
{
	int V=5;
	
	vector<int> adj[5];
	
	addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    
	printGraph(adj, V);
    
    
	return 0;
}
