#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int n,int i,int I,int D,vector<vector<vector<int>>> &dp)
{
    if(i < 0)  return 0;
    
    if(dp[i][I][D] != -1)  return dp[i][I][D];
    
    int ans = INT_MIN;
    
    if(I == n || a[i] < a[I])
    ans = max(ans , Rec(a,n,i-1,i,D,dp) + 1);
    
    if(D == n || a[i] > a[D])
    ans = max(ans , Rec(a,n,i-1,I,i,dp) + 1);
    
    ans = max(ans , Rec(a,n,i-1,I,D,dp));
    
    return dp[i][I][D] = ans;
}
int MinElements(vector<int> &a,int n)
{
	vector<vector<vector<int>>> dp(n,vector<vector<int>>(n+1,vector<int>(n+2,-1)));
	    
    return n-Rec(a,n,n-1,n,n,dp);
}
signed main()
{
	vector<int> a = {7, 8, 1, 2, 4, 6, 3, 5, 2, 1, 8, 7};
	int n = a.size();
	
	cout<< MinElements(a,n) <<endl;
    
	return 0;
}
