#include<bits/stdc++.h>
using namespace std;
int MinStepUntill(string s1,int n1,string s2,int n2,vector<vector<int>> &dp)
{
	if(n1 < 0 || n2 < 0)
	return ((max(n1,n2)>=0) ? max(n1,n2) + 1 : 0);
	
	if(dp[n1][n2] != -1)
	return dp[n1][n2];
	
	if(s1[n1] == s2[n2])
	return dp[n1][n2] = MinStepUntill(s1,n1-1,s2,n2-1,dp);
	
	return dp[n1][n2] = 1 + min( MinStepUntill(s1,n1-1,s2,n2-1,dp) , min(MinStepUntill(s1,n1-1,s2,n2,dp) , MinStepUntill(s1,n1,s2,n2-1,dp) ) );
}
int MinStep(string s1,int n1,string s2,int n2)
{
	vector<vector<int>> dp(n1,vector<int>(n2,-1));
	
	return MinStepUntill(s1,n1-1,s2,n2-1,dp);
}
signed main()
{
	string s1 = "geek";
	string s2 = "gesek";
	
	cout<< MinStep(s1 , s1.length()-1 , s2 , s2.length()-1) <<endl;
    
	return 0;
}
