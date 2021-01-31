#include<bits/stdc++.h>
using namespace std;
int Rec(string &s,int l,int r,vector<vector<int>> &dp)
{
    if(l == r)  return 1;
    
    if(l > r)  return 0;
    
    if(dp[l][r] != -1)  return dp[l][r];
    
    int case1 = Rec(s,l+1,r,dp) + 1;
    
    int case2 = INT_MAX;
    
    for(int i = l+1 ; i <= r ; i++)
    if(s[i]==s[l])
    case2 = min( case2 , ( (l+1 == i) ? 1 : Rec(s,l+1,i-1,dp) ) + Rec(s,i+1,r,dp) );
    
    return dp[l][r] = min(case1 , case2);
}
int RepeatedDelete(string &s,int n)
{
	vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
	    
	return Rec(s,0,s.length()-1,dp);
}
signed main()
{
	string s = "2553432";
	int n = s.length();
	
	cout<< RepeatedDelete(s,n) <<endl;
	
	return 0;
}
