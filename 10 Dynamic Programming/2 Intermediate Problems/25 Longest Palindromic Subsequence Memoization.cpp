#include<bits/stdc++.h>
using namespace std;
int Rec(string &s,int f,int e,vector<vector<int>> &dp)
{
    if(f >= e)  return 0;
    
    if(dp[f][e] != -1)  return dp[f][e];
    
    if(s[f] == s[e])
    return dp[f][e] = min( Rec(s,f+1,e-1,dp) , min( Rec(s,f+1,e,dp) + 1 , Rec(s,f,e-1,dp) + 1 ) );
    
    return dp[f][e] = min( Rec(s,f+1,e,dp) + 1 , Rec(s,f,e-1,dp) + 1 );
}
int LPS(string s,int n)
{
	vector<vector<int>> dp(n,vector<int>(n,-1));
	    
	return n - Rec(s,0,n-1,dp);
}
signed main()
{
	string s = "GEEKSFORGEEKS";
	int n = s.length();
    
    cout<< LPS(s,n) <<endl;
    
	return 0;
}
