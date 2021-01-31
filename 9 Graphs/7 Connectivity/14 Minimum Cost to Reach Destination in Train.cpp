#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int minCost(int cost[4][4])
{
	int n=4;
	
	vector<int> dist(n,INT_MAX);
	dist[0]=0;
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		dist[j]=min(dist[j],cost[i][j]+dist[i]);
	}
	
	return dist[n-1];
}
signed main()
{
	int cost[4][4] = { {  0  ,  15 ,  80 , 90 }, 
                       { INF ,  0  ,  40 , 50 }, 
                       { INF , INF ,  0  , 70 }, 
                       { INF , INF , INF , 0  } 
                     };
                     
    cout << "The Minimum cost to reach station " << 4 << " is " << minCost(cost);
    
	return 0;
}
