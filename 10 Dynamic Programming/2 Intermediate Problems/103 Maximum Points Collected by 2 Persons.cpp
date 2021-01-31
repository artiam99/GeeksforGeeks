#include<bits/stdc++.h>
using namespace std;
int MaxPoints(vector<vector<int>> &a,int n,int m)
{
	int dp1S[n][m] , dp1E[n][m] , dp2S[n][m] , dp2E[n][m] ;
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < m ; j++)
	dp1S[i][j] = a[i][j] + max( ((i > 0) ? dp1S[i-1][j] : 0) , ((j > 0) ? dp1S[i][j-1] : 0) );
	
	for(int i = n-1 ; i >= 0 ; i--)
	for(int j = m-1 ; j >= 0 ; j--)
	dp1E[i][j] = a[i][j] + max( ((i < n-1) ? dp1E[i+1][j] : 0) , ((j < m-1) ? dp1E[i][j+1] : 0) );
	
	for(int i = n-1 ; i >= 0 ; i--)
	for(int j = 0 ; j < m ; j++)
	dp2S[i][j] = a[i][j] + max( ((i < n-1) ? dp2S[i+1][j] : 0) , ((j > 0) ? dp2S[i][j-1] : 0) );
	
	for(int i = 0 ; i < n ; i++)
	for(int j = m-1 ; j >= 0 ; j--)
	dp2E[i][j] = a[i][j] + max( ((i > 0) ? dp2E[i-1][j] : 0) , ((j < m-1) ? dp2E[i][j+1] : 0) );
	
	int ans = INT_MIN;
	
	for(int i = 1 ; i < n-1 ; i++)
	for(int j = 1 ; j < m-1 ; j++)
	ans = max( ans , max( dp1S[i-1][j] + dp1E[i+1][j] + dp2S[i][j-1] + dp2E[i][j+1] , dp1S[i][j-1] + dp1E[i][j+1] + dp2S[i+1][j] + dp2E[i-1][j] ));  // Meeting Cell Points not included
	
	if(ans != INT_MIN)
	return ans;
	
	return -1;
}
signed main()
{
	vector<vector<int>> a = { {100 , 100 , 100 , 100},
			                  {100 , 100 , 100 , 100},
			                  {100 , 0   , 100 , 100},
			                  {100 , 100 , 100 , 100} };
	int n = a.size();
	int m = a[0].size();
	
	cout<< MaxPoints(a,n,m) <<endl;
	
	return 0;
}
