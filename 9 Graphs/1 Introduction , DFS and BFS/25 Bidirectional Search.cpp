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
	g->adj[v].push_back(u);
}
void Print(vector<int> &p1,vector<int> &p2,int x)
{
	int x1=p1[x],x2=x;
	stack<int> st;
	while(x1!=-1)
	{
		st.push(x1);
		x1=p1[x1];
	}
	while(st.size())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	while(x2!=-1)
	{
		cout<<x2<<" ";
		x2=p2[x2];
	}
	cout<<endl;
}
void PrintPath(Graph* g,int s,int d)
{
	queue<int> qs,qd;
	
	vector<int> sparent(g->V),dparent(g->V);
	
	vector<bool> svis(g->V,false),dvis(g->V,false);
	
	qs.push(s);
	sparent[s]=-1;
	svis[s]=1;
	
	qd.push(d);
	dparent[d]=-1;
	dvis[d]=1;
	
	while(qs.size() && qd.size())
	{
		int ssize=qs.size();
		
		while(ssize--)
		{
			int x=qs.front(); qs.pop();
			
			for(auto i:g->adj[x])
			{
				if(!svis[i])
				{
					sparent[i]=x;
			        
					if(dvis[i])
					{
						Print(sparent,dparent,i);
						return;
					}
					svis[i]=1;
					qs.push(i);
				}
			}
		}
		
		int dsize=qd.size();
		
		while(dsize--)
		{
			int x=qd.front(); qd.pop();
			
			for(auto i:g->adj[x])
			{
				if(!dvis[i])
				{
					dparent[i]=x;
					
					if(svis[i])
					{
						Print(sparent,dparent,i);
						return;
					}
					dvis[i]=1;
					qd.push(i);
				}
			}
		}
	}
	cout<<-1<<endl;
}
signed main()
{
	int V=15;
	Graph* g=CreateGraph(V);
	
	addEdge(g, 0, 4);
    addEdge(g, 1, 4);
    addEdge(g, 2, 5);
    addEdge(g, 3, 5);
    addEdge(g, 4, 6);
    addEdge(g, 5, 6);
    addEdge(g, 6, 7);
    addEdge(g, 7, 8);
    addEdge(g, 8, 9);
    addEdge(g, 8, 10);
    addEdge(g, 9, 11);
    addEdge(g, 9, 12);
    addEdge(g, 10, 13);
    addEdge(g, 10, 14);
    
    int s=0,d=11;
    
    PrintPath(g,s,d);
	
	return 0;
}
