#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
struct Graph
{
	int V;
	
	vector<int> *adj;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<int>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
}
bool isvisited(int x,vector<int> &path)
{
	for(auto i:path)
	if(i==x)
	return true;
	
	return false;
}
void PrintallPaths(Graph* g,int s,int d)
{
	queue<vector<int>> q;
	
	q.push(vector<int>(1,s));
	
	while(q.size())
	{
		vector<int> path=q.front();
		q.pop();
		
		int last=path[path.size()-1];
		
		if(last==d)
		{
			for(auto i:path)
			cout<<i<<" ";
			cout<<endl;
		}
		
		for(auto i:g->adj[last])
		{
			if(!isvisited(i,path))
			{
				vector<int> newpath(path);
				newpath.push_back(i);
				
				q.push(newpath);
			}
	    }
	}
}
signed main()
{
	int V=4;
	Graph* g=CreateGraph(V);
	
	addEdge(g,0,3);
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,1,3);
	addEdge(g,2,0);
	addEdge(g,2,1);
	
	int s=2,d=3;
	
	PrintallPaths(g,s,d);
	
	return 0;
}
