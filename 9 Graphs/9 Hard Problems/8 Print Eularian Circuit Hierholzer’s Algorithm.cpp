#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
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
void PrintEulerCircuit(Graph* g)// Valid iff all vertices has equal in and out degree. and Non-zero degree vertices are part of one Strongly Connected Component
{
	unordered_map<int,int> edge_left;
	
	for(int i=0;i<g->V;i++)
	edge_left[i]=g->adj[i].size();
	
	stack<int> st;
	int curr_v=0;
	st.push(curr_v);
	
	vector<int> circuit;
	
	while(st.size())
	{
		if(edge_left[curr_v])
		{
			st.push(curr_v);
			
			edge_left[curr_v]--;
			
			int next=g->adj[curr_v].back();
			
			g->adj[curr_v].pop_back();
			
			curr_v=next;
		}
		else
		{
			circuit.push_back(curr_v);
			
			curr_v=st.top();
			
			st.pop();
		}
	}
	
	for(int i=circuit.size()-1;i>=0;i--)
	{
		cout<<circuit[i];
		
		if(i)
		cout<<" -> ";
	}
	cout<<endl;
}
signed main()
{
	Graph* g=CreateGraph(7);
	 
    addEdge(g, 0, 1); 
    addEdge(g, 0, 6); 
    addEdge(g, 1, 2); 
    addEdge(g, 2, 0); 
    addEdge(g, 2, 3); 
    addEdge(g, 3, 4); 
    addEdge(g, 4, 2); 
    addEdge(g, 4, 5); 
    addEdge(g, 5, 0); 
    addEdge(g, 6, 4); 
    
	PrintEulerCircuit(g);
    
    return 0;
}
