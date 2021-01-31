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
int MinInsertion(string s)
{
	vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
	    
	return Rec(s,0,s.length()-1,dp);
}
signed main()
{
	string s = "geeks";
	
	cout<< MinInsertion(s) <<endl;
	
	return 0;
}
