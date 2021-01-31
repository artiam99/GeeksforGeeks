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
	
	vector<int> value;
};
Graph* CreateGraph(int V)
{
	Graph* g=new Graph;
	
	g->V=V;
	
	g->adj=new vector<int>[V];
	
	for(int i=0;i<V;i++)
	g->value.push_back(0);
	
	return g;
}
void addEdge(Graph* g,int u,int v)
{
	g->adj[u].push_back(v);
	g->adj[v].push_back(u);
}
void BFT(Graph* g,vector<bool> &seive,int s,int n)
{
	int ind=0;
	queue<pair<int,int>> q;
	
	q.push({ind,s});
	g->value[ind++]=s;
	seive[s]=0;
	
	while(q.size())
	{
		pair<int,int> p=q.front(); q.pop();
		
		for(int i=0;i<n;i++)
		{
			int y=p.second;
			int d=(y/(int)pow(10,i))%10;
			y-=d*pow(10,i);
			
			for(int j=0;j<10;j++)
			{
				y+=pow(10,i)*j;
				
				if(seive[y])
				{
					addEdge(g,p.first,ind);
					q.push({ind,y});
					g->value[ind++]=y;
					seive[y]=0;
				}
				
				y-=pow(10,i)*j;
			}
		}
	}
}
void FindShortestPath(int s,int d)
{
	int n=ceil(log10(max(s,d)+1));
	
	int x=0;
	
	for(int i=0;i<n;i++)
	x+=9*pow(10,i);
	
	vector<bool> seive(x+1,1);
	seive[0]=seive[1]=0;
	
	for(int i=2;i<sqrt(x);i++)
	{
		if(seive[i])
		{
			for(int j=2;j*i<x;j++)
			seive[i*j]=0;
		}
	}
	
	int V=0;
	for(int i=0;i<x+1;i++)
	if(seive[i]==1)
	V++;
	
	Graph* g=CreateGraph(V);
	
	BFT(g,seive,s,n);
	
	queue<int> q;
	
	q.push(0);
	
	vector<bool> vis(V,0);
	vis[0]=1;
	
	int lvl=0;
	
	while(q.size())
	{
		int size=q.size();
		bool flag=1;
		
		while(size--)
		{
			if(g->value[q.front()]==d)
			{
			    flag=0;
			    break;
			}
			int f=q.front();
			q.pop();
			
			for(auto j:g->adj[f])
			if(!vis[j])
			{
				vis[j]=1;
				q.push(j);
			}
		}
		if(!flag)
		break;
		lvl++;
	}
	
	cout<<lvl<<endl;
}
signed main()
{
	int s=1033;
	int d=8179;
	
	FindShortestPath(s,d);
		
	return 0;
}
