#include<bits/stdc++.h>
using namespace std;
#define int long long
void PrintSink(vector<vector<bool>> &adj,int n)
{
	for(int i=0;i<n;i++)
	{
		bool flag=0;
		for(int j=0;j<n;j++)
		if(adj[i][j])
		{
			flag=true;
			break;
		}
		
		if(!flag)
		cout<<i+1<<" ";
	}
	cout<<endl;
}
signed main()
{
	vector<vector<bool>> adj={{0,0,0,0},
						  	  {0,0,1,0},
							  {0,0,0,0},
							  {0,0,1,0} };
	int n=adj.size();
	
	PrintSink(adj,n);
	
	return 0;
}
