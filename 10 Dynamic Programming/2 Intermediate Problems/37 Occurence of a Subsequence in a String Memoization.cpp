#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int Rec(string &s,int i,string &t,int j,vector<vector<int>> &dp)
{
    if(j==t.length()) return 1;
    
    if(i==s.length()) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s[i]==t[j])
    return dp[i][j] = (Rec(s,i+1,t,j+1,dp)%mod  + Rec(s,i+1,t,j,dp)%mod)%mod;
    
    return dp[i][j] = Rec(s,i+1,t,j,dp)%mod;
}
int subsequenceCount(string s, string t)
{
    vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
    return Rec(s,0,t,0,dp);
}
signed main()
{
	string s = "geeksforgeeks";
	string t = "ge" ;
	
	cout<< subsequenceCount(s,t) <<endl;
    
	return 0;
}
