#include<bits/stdc++.h>
using namespace std;
int MaxDotProd(vector<int> &a,int n,vector<int> &b,int m)
{
	int dp[n+1][m+1];
	
	for(int i = 0 ; i <= n ; i++)
	for(int j = 0 ; j <= m ; j++)
	{
		if(j == 0)  dp[i][j] = 0;
		
		else if(i == 0)  dp[i][j] = INT_MIN;
		
		else  dp[i][j] = max( a[i-1] * b[j-1] + dp[i-1][j-1] , dp[i-1][j]);
	}
	return dp[n][m];
}
signed main()
{
	vector<int> a = {2, 3, 1, 7, 8};
	int n = a.size();
	
	vector<int> b = {3, 6, 7};
	int m = b.size();
	
	cout<< MaxDotProd(a,n,b,m) <<endl;
    
	return 0;
}
