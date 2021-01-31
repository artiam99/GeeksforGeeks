#include<bits/stdc++.h>
using namespace std;
int Rec(vector<vector<char>> &a,int n,int m,int x1,int y1,int x2,int y2,vector<vector<vector<int>>> &dp)
{
	if(x1 == n-1 && y1 == m-1)  return (a[x1][y1] == '*');
	
	if(a[x1][y1] == '#' || a[x2][y2] == '#')  return INT_MIN;
	
	if(dp[x1+y1][x1][x2] != -1)  return dp[x1+y1][x1][x2];
	
	int ans = INT_MIN;
	
	if(x1 != n-1)
	{
		if(x2 != n-1)  ans = max(ans , Rec(a , n , m , x1+1 , y1 , x2+1 , y2 , dp));
		
		if(y2 != m-1)  ans = max(ans , Rec(a , n , m , x1+1 , y1 , x2 , y2+1 , dp));
	}
	
	if(y1 != m-1)
	{
		if(x2 != n-1)  ans = max(ans , Rec(a , n , m , x1 , y1+1 , x2+1 , y2 , dp));
		
		if(y2 != m-1)  ans = max(ans , Rec(a , n , m , x1 , y1+1 , x2 , y2+1 , dp));
	}
	
	return dp[x1+y1][x1][x2] = ans + (a[x1][y1] == '*') + (!(x1 == x2 && y1 == y2) && a[x2][y2] == '*');
}
int MaxPoints(vector<vector<char>> &a,int n,int m)
{
	vector<vector<vector<int>>> dp(n+m,vector<vector<int>>(n,vector<int>(n,-1)));
	
	return Rec(a , n , m , 0 , 0 , 0 , 0 , dp);
}
signed main()
{
	vector<vector<char>> a = { { '.', '*', '.', '*', '.' }, 
					           { '*', '#', '#', '#', '.' }, 
				    	       { '*', '.', '*', '.', '*' }, 
						       { '.', '#', '#', '#', '*' }, 
						       { '.', '*', '.', '*', '.' } };
	int n = a.size();
	int m = a[0].size();
	
	cout<< MaxPoints(a,n,m) <<endl;
    
	return 0;
}
