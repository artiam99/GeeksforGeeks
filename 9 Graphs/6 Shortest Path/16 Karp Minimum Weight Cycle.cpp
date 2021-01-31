#include<bits/stdc++.h>
using namespace std;

const int V = 4;

struct edge
{
	int from , weight;
};

vector<edge> edges[V];

void addedge(int u , int v , int w)
{
	edges[v].push_back({u , w});
}

void shortestpath(int dp[][V])
{
	for (int i = 0 ; i <= V ; i++)
	for (int j = 0 ; j < V ; j++)
	dp[i][j] = -1;
	
	dp[0][0] = 0;

	for(int i = 1 ; i <= V; i++)
	for(int j = 0 ; j < V ; j++)
	for(int k = 0 ; k < edges[j].size() ; k++)
	if(dp[i-1][edges[j][k].from] != -1)
	{
		int curr_wt = dp[i-1][edges[j][k].from] + edges[j][k].weight;
		
		if (dp[i][j] == -1)  dp[i][j] = curr_wt;
		
		else  dp[i][j] = min(dp[i][j], curr_wt);
	}
}

double minAvgWeight()
{
	int dp[V+1][V];
	
	shortestpath(dp);

	double avg[V];
	
	for(int i = 0 ; i < V ; i++)
	avg[i] = -1;

	for(int i = 0 ; i < V ; i++)
	if(dp[V][i] != -1)
	{
		for (int j = 0 ; j < V ; j++)
		if(dp[j][i] != -1)
		avg[i] = max(avg[i] , ((double)dp[V][i] - dp[j][i]) / (V-j));
	}

	double result = avg[0];
	
	for(int i = 0 ; i < V ; i++)
	if (avg[i] != -1 && avg[i] < result)
	result = avg[i];

	return result;
}

int main()
{
	addedge(0 , 1 , 1);
	addedge(0 , 2 , 10);
	addedge(1 , 2 , 3);
	addedge(2 , 3 , 2);
	addedge(3 , 1 , 0);
	addedge(3 , 0 , 8);

	cout << minAvgWeight() << endl;

	return 0;
}

