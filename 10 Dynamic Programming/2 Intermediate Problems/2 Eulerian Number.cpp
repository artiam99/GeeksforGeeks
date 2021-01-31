#include<bits/stdc++.h>
using namespace std;
int Rec(int n,int m,vector<vector<int>> &dp)
{
	if(m >= n || n == 0) return 0;
	
	if(m == 0) return 1;
	
	if(dp[n][m] != -1) return dp[n][m];
	
	return dp[n][m] = (n - m) * Rec(n-1 , m-1 , dp) + (m + 1) * Rec(n-1 , m , dp);
}
int NoofPermutations(int n,int m)
{
	vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	
	return Rec(n,m,dp);
}
signed main()
{
	int n = 3 , m = 1; // Number of Permutation of 1 to n where only m numbers greater than previous Numbers
	
	cout<< NoofPermutations(n , m) <<endl;
    
	return 0;
}

