#include<bits/stdc++.h>
using namespace std;
struct Graph
{
	int V;
	vector<int> *adj;
};
Graph* CreateGraph(int V)
{
	Graph *g=new Graph;
	
	g->V=V;
	g->adj=new vector<int>[V];
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
}
void DFS(Graph *g,int u,vector<int> &disc,vector<int> &low,vector<bool> &rec,stack<int> &st,int &timer)
{
	disc[u]=low[u]=++timer;
	
	st.push(u);
	rec[u]=true;
	
	for(auto i:g->adj[u])
	{
		if(disc[i] == -1)
		{
			DFS(g,i,disc,low,rec,st,timer);
			low[u]=min(low[u],low[i]);
		}
		else if(rec[i])
		low[u]=min(low[u],disc[i]);
	}
	
	if(disc[u] == low[u])
	{
		while(st.top()!=u)
		{
			cout<<st.top()<<" ";
			rec[st.top()]=false;
			st.pop();
		}
		cout<<st.top()<<endl;
		st.pop();
		rec[u]=false;
	}
}
void SCC(Graph* g)
{
	vector<int> disc(g->V,-1);
	vector<int> low(g->V);
	vector<bool> rec(g->V);
	stack<int> st;
	
	int timer=0;
	
	for(int i=0;i<g->V;i++)
	if(disc[i] == -1)
	DFS(g,i,disc,low,rec,st,timer);
}
signed main()
{
	cout << "SCCs in first graph \n";
	    
	Graph *g1=CreateGraph(5);
    
	addEdge(g1, 1, 0);
    addEdge(g1, 0, 2);
    addEdge(g1, 2, 1);
    addEdge(g1, 0, 3);
    addEdge(g1, 3, 4);
    
	SCC(g1);

    cout << "\nSCCs in second graph \n";
    
	Graph *g2=CreateGraph(4);
    
	addEdge(g2, 0, 1);
    addEdge(g2, 1, 2);
    addEdge(g2, 2, 3);
    
	SCC(g2);

    cout << "\nSCCs in third graph \n";
    
	Graph *g3=CreateGraph(7);
    
	addEdge(g3, 0, 1);
    addEdge(g3, 1, 2);
    addEdge(g3, 2, 0);
    addEdge(g3, 1, 3);
    addEdge(g3, 1, 4);
    addEdge(g3, 1, 6);
    addEdge(g3, 3, 5);
    addEdge(g3, 4, 5);
    
	SCC(g3);
    
    cout << "\nSCCs in fourth graph \n";

    Graph *g4=CreateGraph(11); 

    addEdge(g4, 0,1);
	addEdge(g4, 0,3);
    addEdge(g4, 1,2);
	addEdge(g4, 1,4);
    addEdge(g4, 2,0);
	addEdge(g4, 2,6);
    addEdge(g4, 3,2);
    addEdge(g4, 4,5);
	addEdge(g4, 4,6);
    addEdge(g4, 5,6);
	addEdge(g4, 5,7);
	addEdge(g4, 5,8);
	addEdge(g4, 5,9);
    addEdge(g4, 6,4);
    addEdge(g4, 7,9);
    addEdge(g4, 8,9);
    addEdge(g4, 9,8);
    
	SCC(g4);

    cout << "\nSCCs in fifth graph \n";
    
	Graph *g5=CreateGraph(5);
   
    addEdge(g5, 0,1);
    addEdge(g5, 1,2);
    addEdge(g5, 2,3);
    addEdge(g5, 2,4);
    addEdge(g5, 3,0);
    addEdge(g5, 4,2);
    
	SCC(g5);
  
    return 0; 
}
