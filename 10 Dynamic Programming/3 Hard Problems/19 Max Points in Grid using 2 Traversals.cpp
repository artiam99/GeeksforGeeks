#include<bits/stdc++.h>
using namespace std;
int Rec(vector<vector<int>> &a,int n,int m,int x,int y1,int y2,vector<vector<vector<int>>> &dp)
{
	if(x == n-1)  return ((y1 == 0 && y2 == m-1) ? a[x][y1] + a[x][y2] : INT_MIN);
	
	if(dp[x][y1][y2] != -1)  return dp[x][y1][y2];
	
	int ans = INT_MIN;
	
	if(y1 != 0)
	{
		if(y2 != 0)  ans = max( ans , Rec(a , n , m , x+1 , y1-1 , y2-1 , dp) );
		
		ans = max( ans , Rec(a , n , m , x+1 , y1-1 , y2 , dp) );
		
		if(y2 != m-1)  ans = max( ans , Rec(a , n , m , x+1 , y1-1 , y2+1 , dp) );
	}
	
	if(y2 != 0)  ans = max( ans , Rec(a , n , m , x+1 , y1 , y2-1 , dp) );
	
	ans = max( ans , Rec(a , n , m , x+1 , y1 , y2 , dp) );
	
	if(y2 != m-1)  ans = max( ans , Rec(a , n , m , x+1 , y1 , y2+1 , dp) );
	
	if(y1 != m-1)
	{
		if(y2 != 0)  ans = max( ans , Rec(a , n , m , x+1 , y1 +1 , y2-1 , dp) );
		
		ans = max( ans , Rec(a , n , m , x+1 , y1+1 , y2 , dp) );
		
		if(y2 != m-1)  ans = max( ans , Rec(a , n , m , x+1 , y1+1 , y2+1 , dp) );
	}
	
	return dp[x][y1][y2] = ans + a[x][y1] + ( (y1 != y2) ? a[x][y2] : 0 );
}
int MaxPoints(vector<vector<int>> &a,int n,int m)
{
	vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
	
	return Rec(a , n , m , 0 , 0 , m-1 , dp);
}
signed main()
{
	vector<vector<int>> a = { {3, 6,  8,  2},
                    		  {5, 2,  4,  3},
                    		  {1, 1, 20, 10},
                    		  {1, 1, 20, 10},
                    		  {1, 1, 20, 10} };
	int n = a.size();
	int m = a[0].size();
	
	cout<< MaxPoints(a,n,m) <<endl;
    
	return 0;
}
