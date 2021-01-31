#include<bits/stdc++.h>
using namespace std;
int SubSecProdlessthanK(vector<int> &a,int n,int k)
{
	int dp[k+1][n+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j] = dp[i][j-1];
			
			if(a[j-1] <= i && a[j-1] > 0)
			dp[i][j] += dp[i/a[j-1]][j-1] + 1;
		}
	}
	return dp[k][n];
}
signed main()
{
	vector<int> a = {4, 8, 7, 2};
	int n=a.size();
	int k=50;
    
    cout<< SubSecProdlessthanK(a,n,k) <<endl;
    
	return 0;
}
