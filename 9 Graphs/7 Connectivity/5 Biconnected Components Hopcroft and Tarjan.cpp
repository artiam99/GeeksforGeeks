#include<bits/stdc++.h>
using namespace std;
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
	g->adj[v].push_back(u);
}
void DFS(Graph* g,int u,stack<pair<int,int>> &st,vector<int> &disc,vector<int> &low,vector<int> &parent,int &timer,int &count)
{
	disc[u]=low[u]=++timer;
	
	int children=0;
	
	for(auto i:g->adj[u])
	{
		if(disc[i] == -1)
		{
			parent[i]=u;
			
			children++;
			
			st.push({u,i});
			
			DFS(g,i,st,disc,low,parent,timer,count);
			
			low[u]=min(low[u],low[i]);
			
			if((parent[u]==-1 && children > 1) || (parent[u]!=-1 && disc[u] > 1 && low[i]>=disc[u]))
			{
				while(st.top().first != u || st.top().second != i)
				{
					cout<<st.top().first<<" --- "<<st.top().second<<" , ";
					
					st.pop();
				}
				cout<<st.top().first<<" --- "<<st.top().second<<endl<<endl;
				
				st.pop();
				
				count++;
			}
		}
		else if(i != parent[u])
		{
			low[u]=min(low[u],disc[i]);
			
			if(disc[i] < disc[u])
			st.push({u,i});
		}
	}
}
void BiconnectedComponents(Graph* g,int &count)
{
	vector<int> parent(g->V,-1);
	vector<int> disc(g->V,-1);
	vector<int> low(g->V,-1);
	
	stack<pair<int,int>> st;
	
	for(int i=0;i<g->V;i++)
	{
		int timer=0;
		
		if(disc[i]==-1)
		DFS(g,i,st,disc,low,parent,timer,count);
		
		int flag=0;
		while(st.size())
		{
			flag=1;
			cout<<st.top().first<<" --- "<<st.top().second;
			
			if(st.size() > 1)
			cout<<" , ";
			else
			cout<<endl<<endl;
			
			st.pop();
		}
		if(flag)
		count++;
	}
}
signed main()
{
	
    Graph *g=CreateGraph(12);
    
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);
    addEdge(g, 1, 5);
    addEdge(g, 0, 6);
    addEdge(g, 5, 6);
    addEdge(g, 5, 7);
    addEdge(g, 5, 8);
    addEdge(g, 7, 8);
    addEdge(g, 8, 9);
    addEdge(g, 10, 11);
    
    int count=0;
    
    BiconnectedComponents(g,count);
    
    cout << "Above are " << count << " biconnected components in graph";
	
	return 0;
}
