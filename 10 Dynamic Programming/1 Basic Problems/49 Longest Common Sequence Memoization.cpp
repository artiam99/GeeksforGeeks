#include<bits/stdc++.h>
using namespace std;
int LCSuntill(string s1,int n,string s2,int m,vector<vector<int>> &dp)
{
	if(n == 0 || m == 0)  return 0;
	
	if(dp[n][m] != -1)  return dp[n][m];
	
	if(s1[n-1] == s2[m-1])  return dp[n][m] = LCSuntill(s1,n-1,s2,m-1,dp) + 1;
	
	return dp[n][m] = max( LCSuntill(s1,n-1,s2,m,dp) , LCSuntill(s1,n,s2,m-1,dp) );
}
int LCS(string s1,int n,string s2,int m)
{
	vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	
	return LCSuntill(s1,n,s2,m,dp);
}
signed main()
{
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	int n = s1.length();
	int m = s2.length();
    
    cout<< LCS(s1,n,s2,m) <<endl;
    
	return 0;
}
