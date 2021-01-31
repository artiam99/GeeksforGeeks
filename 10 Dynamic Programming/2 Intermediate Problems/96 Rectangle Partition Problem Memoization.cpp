#include<bits/stdc++.h>
using namespace std;
int Rec(int m,int n,vector<vector<int>> &dp)
{
    if(m==0 || n==0)  return 0;
    
    if(m==1)  return n;
    
    if(n==1)  return m;
    
    if(dp[m][n] != -1)  return dp[m][n];
    
    int ans = INT_MAX;
    
    for(int i = 1 ; i <= min(m,n) ; i++)
    ans = min(ans , 1 + min( Rec(m-i,n,dp) + Rec(i,n-i,dp) , Rec(m,n-i,dp) + Rec(m-i,i,dp) ) );
    
    return dp[m][n] = ans;
}
int MinSquares(int m,int n)
{
	vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
	    
    return Rec(m,n,dp);
}
signed main()
{
	int m = 11 , n = 13;  // Minimum Number of Squares that can fit in M*N Rectangle  .. This is NP Hard Problem ... Above is approximate Solution ans 8 ... Exact ans is 6 -> 5 4 4 7 1 6
	
	cout<< MinSquares(m,n) <<endl;
	
	return 0;
}
