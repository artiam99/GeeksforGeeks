#include<bits/stdc++.h>
using namespace std;
int Rec(int n,int m,int x,vector<vector<int>> &dp)
{
    if(n==0)
    return (x==0);
    
    if(dp[n][x] != -1) return dp[n][x];
    
    dp[n][x]=0;
    for(int i=1;i<=m;i++)
    dp[n][x] += ((i<=x) ? Rec(n-1,m,x-i,dp) : 0);
    
    return dp[n][x];
}
int NumberofWays(int n , int m , int x)
{
    vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
    
    return Rec(n,m,x,dp);
}
signed main()
{
	int n = 3 , m = 6 , x = 12; // n dice m faces with numbers 1 to m .. Find no of ways to find x 
	
	cout<< NumberofWays(n,m,x) <<endl;
    
	return 0;
}

