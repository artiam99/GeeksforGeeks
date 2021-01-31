#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int Rec(int n,int k,bool b,vector<vector<pair<int,int>>> &dp)
{
    if(n < 1 || k < 0)  return 0;
    
    if(n == 1 && k == 0)  return 1;
    
    if(b && dp[n][k].first != -1)  return dp[n][k].first;
    
    if(!b && dp[n][k].second != -1)  return dp[n][k].second;
    
    if(b)
    return  dp[n][k].first =  (Rec(n-1,k-1,1,dp) % mod + Rec(n-1,k,0,dp) % mod) % mod;
    
    return  dp[n][k].second =  (Rec(n-1,k,1,dp) % mod + Rec(n-1,k,0,dp) % mod) % mod;
}
int countStrings(int n, int k)
{
    vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(k+1,{-1,-1}));
    
    return (Rec(n,k,0,dp) % mod + Rec(n,k,1,dp) % mod) % mod;
}
signed main()
{
	int n = 5 , k = 2;
	
	cout<< countStrings(n,k) <<endl;
    
	return 0;
}
