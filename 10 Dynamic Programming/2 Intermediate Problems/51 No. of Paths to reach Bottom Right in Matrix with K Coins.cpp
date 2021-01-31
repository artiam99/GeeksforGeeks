#include<bits/stdc++.h>
using namespace std;
int pathCountDP(vector<vector<int>> &a,int n,int k)
{
	int dp[n][n][k+1];  memset(dp,0,sizeof(dp));
	
	if(a[0][0] <= k)
	dp[0][0][a[0][0]] = 1;
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < n ; j++)
	for(int l = a[i][j] ; l <= k ; l++)
	dp[i][j][l] += ( (i > 0) ? dp[i-1][j][l-a[i][j]] : 0 ) + ( (j > 0) ? dp[i][j-1][l-a[i][j]] : 0 );
	
	return dp[n-1][n-1][k];
}
signed main()
{
	vector<vector<int>> a = { {1, 2, 3},
    		                  {4, 6, 5},
    		                  {3, 2, 1}
    			            };
    int n = a.size();
    
    int k = 12;
    
    cout << pathCountDP(a, n, k) <<endl; 
    
	return 0; 
}
