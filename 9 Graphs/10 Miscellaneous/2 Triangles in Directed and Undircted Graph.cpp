#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
int CountTriangles(vector<vector<int>> &adj,int n,bool isdirected)
{
	int cnt=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			if(adj[i][j] && adj[j][k] && adj[k][i])
			cnt++;
		}
	}
	
	return ((isdirected)?cnt/3:cnt/6);
}
signed main()
{
	int n=4;
	
	vector<vector<int>> adj1={ {0, 1, 1, 0},
             	               {1, 0, 1, 1},
                  		       {1, 1, 0, 1},
                       	       {0, 1, 1, 0} };
	
	cout<< CountTriangles(adj1,n,0) <<endl;
	
	vector<vector<int>> adj2={ {0, 0, 1, 0},
             	               {1, 0, 0, 1},
                  		       {1, 1, 0, 1},
                       	       {0, 0, 1, 0} };
	
	cout<< CountTriangles(adj2,n,1) <<endl;
	                
	return 0;
}
