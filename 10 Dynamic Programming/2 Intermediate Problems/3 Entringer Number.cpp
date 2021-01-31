#include<bits/stdc++.h>
using namespace std;
int Rec(int n,int k,vector<vector<int>> &dp)
{
	if(k == 0 && n == 0) return 1;
	
	if(k == 0) return 0;
	
	if(dp[n][k] != -1) return dp[n][k];
	
	return dp[n][k] = Rec(n , k-1 , dp) + Rec(n-1 , n-k , dp);
}
int NoofPermutations(int n,int k)
{
	vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
	
	return Rec(n,k,dp);
}
signed main()
{
	int n = 4 , k = 3; // The number of permutations of {1, 2, …, n + 1}, starting with k + 1, which, after initially falling, alternatively fall then rise
	
	cout<< NoofPermutations(n , k) <<endl;
    
	return 0;
}

