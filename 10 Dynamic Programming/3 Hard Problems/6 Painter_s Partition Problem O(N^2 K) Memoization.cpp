#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int n,int l,int k,vector<vector<int>> &dp)
{
    if(l == n)  INT_MIN;
    
    if(dp[l][k] != -1)  return dp[l][k];
    
    if(k == 1)  return dp[l][k] = a[n-1] - ((l == 0) ? 0 : a[l-1]);
    
    int ans = INT_MAX;
    
    for(int i = l ; i <= n-k ; i++)
    ans = min(ans , max( a[i] - ((l == 0) ? 0 : a[l-1]) , Rec(a,n,i+1,k-1,dp) ));
    
    return dp[l][k] = ans;
}
int PaintersPartition(vector<int> &a,int n,int k)
{
	for(int i = 1 ; i < n ; i++)
	a[i] += a[i-1];
	
	vector<vector<int>> dp(n,vector<int>(k+1,-1));
	
	return Rec(a,n,0,k,dp) ;
}
signed main()
{
	vector<int> a = {12, 34, 67, 90};
	int n = a.size();
	
	int k = 2;
	
	cout<< PaintersPartition(a,n,k) <<endl;
    
	return 0;
}
