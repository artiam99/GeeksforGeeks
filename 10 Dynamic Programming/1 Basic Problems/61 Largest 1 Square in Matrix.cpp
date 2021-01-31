#include<bits/stdc++.h>
using namespace std;
int MaxSquare(vector<vector<bool>> &a,int n,int m)
{
	vector<vector<int>> dp(n,vector<int>(m));
	
	int mx = 0;
	
	for(int i=0;i<n;i++)
	if(a[i][0]) mx = dp[i][0] = 1;
	
	for(int j=0;j<m;j++)
	if(a[0][j]) mx = dp[0][j] = 1;
	
	for(int i=1;i<n;i++)
	for(int j=1;j<m;j++)
	if(a[i][j])
	{
		dp[i][j] = min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1])) + 1 ;
		
		mx = max(mx , dp[i][j]);
	}
	
	return mx;
}
signed main()
{
	vector<vector<bool>> a = { {0, 1, 1, 0, 1},  
                    		   {1, 1, 0, 1, 0},  
                    		   {0, 1, 1, 1, 0},  
                			   {1, 1, 1, 1, 0},  
                  			   {1, 1, 1, 1, 1},  
                  			   {0, 0, 0, 0, 0} }; 
	int n = a.size() , m = a[0].size();
	
    cout<< MaxSquare(a,n,m) <<endl;
    
	return 0;
}
