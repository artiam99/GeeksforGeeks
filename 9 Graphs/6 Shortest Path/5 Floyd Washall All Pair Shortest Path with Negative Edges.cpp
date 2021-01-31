#include<bits/stdc++.h>
using namespace std;
#define INF 100000
void FloydWashall(int graph[4][4])
{
	int V=4;
	int dist[V][V];
	
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		dist[i][j]=graph[i][j];
	}
	
	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			if(dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
			dist[i][j] = dist[i][k] + dist[k][j];
		}
	}
	
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(dist[i][j]==INF)
			cout<<"INF ";
			else
			cout<<dist[i][j]<<"   ";
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
                    
    FloydWashall(graph);
	
	return 0;
}
