#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int u,v;
	int flow;
	int C; 

	Edge(int u,int v,int flow,int C)
	{
		this->u = u;
		this->v = v;
		this->flow = flow;
		this->C = C;
	}
};
struct Vertex
{
	int h;
	int e_flow;

	Vertex(int h,int e_flow)
	{
		this->h = h;
		this->e_flow = e_flow;
	}
};
struct Graph
{
	int V;
	vector<Vertex> vtx;
	vector<Edge> edge;
};
Graph* CreateGraph(int V)
{
	Graph* g = new Graph;
	
	g->V = V;
	
	for (int i = 0;i<g->V;i++)
	g->vtx.push_back(Vertex(0,0));
	
	return g;
}
void addEdge(Graph* g,int u,int v,int C)
{
	g->edge.push_back(Edge(u,v,0,C));
}
void PreFlow(Graph* g,int s)
{
	g->vtx[s].h = g->V;
	
	for(int i=0;i<g->edge.size();i++)
	{ 
		if(g->edge[i].u == s)
		{
			g->edge[i].flow = g->edge[i].C;

			g->vtx[g->edge[i].v].e_flow += g->edge[i].flow; 

			g->edge.push_back(Edge( g->edge[i].v , s , -g->edge[i].flow , 0 ));
		}
	}
}
int OverFlowVertex(vector<Vertex> &vtx) 
{
	for (int i=1;i<vtx.size()-1;i++)
	if(vtx[i].e_flow > 0)
	return i;

	return -1;
}
void UpdateReverseEdgeFlow(Graph* g,int ind, int flow)
{
	int u = g->edge[ind].v;
	int v = g->edge[ind].u;

	for(int i=0;i<g->edge.size();i++)
	{
		if (g->edge[i].u == u && g->edge[i].v == v)
		{
			g->edge[i].flow -= flow;
			
			return;
		}
	}

	g->edge.push_back(Edge(u, v,0, flow));
}
bool Push(Graph* g,int u) 
{
	for(int i=0;i<g->edge.size();i++)
	{
		if(g->edge[i].u == u)
		{
			if(g->edge[i].flow == g->edge[i].C)
			continue;

			if(g->vtx[u].h > g->vtx[g->edge[i].v].h)
			{
				int flow = min(g->edge[i].C - g->edge[i].flow , g->vtx[u].e_flow);

				g->vtx[u].e_flow -= flow;

				g->vtx[g->edge[i].v].e_flow += flow;

				g->edge[i].flow += flow;
				
				UpdateReverseEdgeFlow(g,i,flow);

				return true;
			}
		}
	}
	return false;
}
void Relabel(Graph* g,int u)
{
	int minh = INT_MAX;

	for(int i=0;i<g->edge.size();i++) 
	{
		if(g->edge[i].u == u)
		{
			if(g->edge[i].flow == g->edge[i].C)
			continue;

			if (g->vtx[g->edge[i].v].h < minh)
			{ 
				minh = g->vtx[g->edge[i].v].h;

				g->vtx[u].h = minh + 1; 
			}
		}
	}
}
int Find_Max_Flow(Graph* g,int s,int t)
{
	PreFlow(g,s);
	
	while(OverFlowVertex(g->vtx) != -1) 
	{
		int u = OverFlowVertex(g->vtx);
		if (!Push(g,u))
	    Relabel(g,u);
	}
 
	return g->vtx.back().e_flow; 
}
signed main()
{
    Graph *g=CreateGraph(6);

    addEdge(g, 0, 1, 16);
    addEdge(g, 0, 2, 13);
    addEdge(g, 1, 2, 10);
    addEdge(g, 2, 1, 4);
    addEdge(g, 1, 3, 12);
    addEdge(g, 2, 4, 14);
    addEdge(g, 3, 2, 9);
    addEdge(g, 3, 5, 20);
    addEdge(g, 4, 3, 7);
    addEdge(g, 4, 5, 4);
    
    int s=0,t=5;
	
	cout<< Find_Max_Flow(g,s,t) <<endl;
	
	return 0;
}
