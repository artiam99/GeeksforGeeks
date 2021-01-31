#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isStarGraph(vector<vector<bool>> &adj,int n)
{
	if(n==1)
	return true;
	
	int in=0,out=0;
	
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		
		for(int j=0;j<n;j++)
		if(adj[i][j])
		cnt++;
		
		if(cnt==1)
		out++;
		else if(cnt==n-1)
		in++;
	}
	
	return (in==1 && out==n-1);
}
signed main()
{
	vector<vector<bool>> adj={{0, 1, 0},
                			  {1, 0, 1},
                			  {0, 1, 0}};
    int n=adj.size();
    
    if(isStarGraph(adj,n))
    cout<<"Star Graph"<<endl;
    else
    cout<<"Not Star Graph"<<endl;
	
	return 0;
}
