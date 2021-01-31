#include<bits/stdc++.h>
using namespace std;
int Rec(int n,int b,int c,int dp[][3][2])
{
    if(n==0)  return 1;
    
    if(b==2 && c==1)  return 1;
    
    if(dp[n][b][c] != -1)  return dp[n][b][c];
    
    int res = Rec(n-1,b,c,dp);
    
    res += ((b < 2) ? Rec(n-1,b+1,c,dp) : 0) + ((c < 1) ? Rec(n-1,b,c+1,dp) : 0);
    
    return dp[n][b][c] = res;
}
int countStrings(int n)
{
	int dp[n+1][3][2];  memset(dp,-1,sizeof(dp));
	    
	return Rec(n,0,0,dp);
}
signed main()
{
	int n = 5;
	
	cout<< countStrings(n) <<endl;
    
	return 0;
}
