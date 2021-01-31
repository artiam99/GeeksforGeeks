#include<bits/stdc++.h>
using namespace std;
#define INF 100000
bool NegativeCycle(int graph[4][4])
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
			if(dist[i][j] > dist[i][k] + dist[k][j])
			dist[i][j]=dist[i][k]+dist[k][j];
		}
	}
	
	for(int i=0;i<V;i++)
	if(dist[i][i]<0)
	return true;
	return false;
}
signed main()
{
	int V=4;
	
	int graph[4][4] = { {0   , 1   , INF , INF}, 
                        {INF , 0   , -1  , INF}, 
                        {INF , INF , 0   ,  -1}, 
                        {-1  , INF , INF ,   0}};
                    
    if(NegativeCycle(graph))
    cout<<"Negative Cycle Present"<<endl;
    else
    cout<<"Negative Cycle Not Present"<<endl;
	
	return 0;
}
