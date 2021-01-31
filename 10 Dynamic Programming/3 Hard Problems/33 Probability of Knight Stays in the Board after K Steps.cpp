#include<bits/stdc++.h>
using namespace std;
double Rec(int x,int y,int k,int N,vector<vector<vector<double>>> &dp)
{
    if(x < 0 || y < 0 || x >= N || y >= N)  return 0;
    
    if(k == 0)  return 1;
    
    if(dp[x][y][k] != -1)  return dp[x][y][k];
    
    return dp[x][y][k] = ( Rec(x+2,y+1,k-1,N,dp) + Rec(x+2,y-1,k-1,N,dp) +
                           Rec(x-2,y+1,k-1,N,dp) + Rec(x-2,y-1,k-1,N,dp) +
                           Rec(x+1,y+2,k-1,N,dp) + Rec(x+1,y-2,k-1,N,dp) +
                           Rec(x-1,y+2,k-1,N,dp) + Rec(x-1,y-2,k-1,N,dp) ) * 0.125;
}
double Knight_Prob(int N,int x,int y,int k)
{
	vector<vector<vector<double>>> dp(N,vector<vector<double>>(N,vector<double>(k+1,-1)));
	    
	return Rec(x,y,k,N,dp);
}
signed main()
{
	int N = 8 , x = 0 , y = 0 , k = 3;
	
	cout<< Knight_Prob(N,x,y,k) <<endl;
	
	return 0;
}
