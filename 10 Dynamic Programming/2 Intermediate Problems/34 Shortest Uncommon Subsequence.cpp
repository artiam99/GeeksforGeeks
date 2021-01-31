#include<bits/stdc++.h>
using namespace std;
int REC(char s1[],int m,char s2[],int n,vector<vector<int>> &dp)
{
    if(m==0)  return 100005;
    
    if(n<=0)  return 1;
    
    if(dp[m][n]!=-1)  return dp[m][n];
    
    int k;
    
    for(k=0;k<n;k++) if(s2[k] == s1[0]) break;
    
    if(k==n)
    return dp[m][n] = 1;
    
    return dp[m][n] = min(REC(s1+1,m-1,s2+k+1,n-k-1,dp) + 1 , REC(s1+1,m-1,s2,n,dp));
}
int SUSS(char s1[],int m,char s2[],int n)
{
	vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	    
	int ans = REC(s1,m,s2,n,dp);
	    
	if(ans>=100005)
	return -1 ;
	    
	return ans ;
}
signed main()
{
	char s1[] = "babab";
	int m = sizeof(s1)/sizeof(char);
	
	char s2[] = "babba";
	int n = sizeof(s2)/sizeof(char);
	
	cout<< SUSS(s1,m,s2,n) <<endl;
    
	return 0;
}
