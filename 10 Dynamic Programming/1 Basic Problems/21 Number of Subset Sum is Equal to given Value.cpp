#include<bits/stdc++.h>
using namespace std;
int SubsetSum(vector<int> &a,int n,int V)
{
	int dp[2][V+1];
	
	for(int i=0;i<V+1;i++)
	dp[0][i]=dp[1][i]=0;
	
	dp[0][0]=1;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=V;j++)
		dp[1 - i%2 ][j] = dp[ i%2 ][j] + ( (j>=a[i]) ? dp[ i%2 ][j - a[i]] : 0 );
	}
	return dp[n%2][V];
}
signed main()
{
	vector<int> a={2, 3, 5, 6, 8, 10};
	int n=a.size();
	
	int V=10;
	
	cout<< SubsetSum(a,n,V);
	    
	return 0;
}
