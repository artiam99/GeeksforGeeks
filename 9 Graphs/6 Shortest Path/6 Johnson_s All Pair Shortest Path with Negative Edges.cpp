#include<bits/stdc++.h>
using namespace std;
#define INF 100000
struct Edge
{
	int u,v,w;
};
void Johnson(int graph[4][4])
{
	int V=4;
	
	vector<Edge> edge;
	
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		if(graph[i][j]!=0 && graph[i][j]!=INF)
		{
			Edge e;
			e.u=i;
			e.v=j;
			e.w=graph[i][j];
			edge.push_back(e);
		}
	}
	for(int i=0;i<V;i++)
	{
		Edge e;
		e.u=-1;
		e.v=i;
		e.w=0;
		edge.push_back(e);
	}
	vector<int> h(V+1,INT_MAX);
	h[0]=0;
	
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<edge.size();j++)
		{
			if(h[edge[j].u+1]!=INT_MAX && h[edge[j].v+1] > h[edge[j].u+1] + edge[j].w)
			h[edge[j].v+1]=h[edge[j].u+1]+edge[j].w;
		}
	}
	
	for(int i=0;i<edge.size();i++)
	{
		if(edge[i].u!=-1)
		graph[edge[i].u][edge[i].v]+=h[edge[i].u+1]-h[edge[i].v+1];
	}
	
	vector<vector<int>> dist(4,vector<int>(4,INF));
	vector<vector<bool>> vis(4,vector<bool>(4,false));
	
	for(int i=0;i<V;i++)
	{
		dist[i][i]=0;
		
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		
		pq.push({0,i});
		
		while(pq.size())
		{
			int u=pq.top().second; pq.pop();
			
			if(!vis[i][u])
			{
				vis[i][u]=true;
				
				for(int j=0;j<V;j++)
				if(!vis[u][j] && graph[u][j]!=INF && graph[u][j]!=0 && dist[i][j] > graph[u][j])
				{
					dist[i][j]=graph[u][j];
					pq.push({dist[i][j],j});
				}
			}
		}
	}
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(dist[i][j]==INF)
			cout<<"INF ";
			else
			cout<<dist[i][j]-h[i+1]+h[j+1]<<"   ";
		}
		cout<<endl;
	}	
}
signed main()
{
	int V=4;
	
	int graph[4][4] = { {0  , -5 , 2  , 3  },  
                        {INF, 0  , 4  , INF},  
                        {INF, INF, 0  , 1  },  
                        {INF, INF, INF, 0  }  
                      };
                    
    Johnson(graph);
	
	return 0;
}
