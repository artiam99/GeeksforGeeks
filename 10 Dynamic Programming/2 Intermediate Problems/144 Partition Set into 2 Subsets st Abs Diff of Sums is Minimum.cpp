#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int i,int curr,int sum,vector<vector<int>> &dp)
{
    if(i < 0)
    return abs(sum-2*curr);
    
    if(dp[i][curr] != -1)  return dp[i][curr];
    
    return dp[i][curr] = min(Rec(a,i-1,curr+a[i],sum,dp) , Rec(a,i-1,curr,sum,dp));
}
int MinimumAbsDiff(vector<int> &a,int n)
{
	int sum = accumulate(a.begin(),a.end(),0);
	    
	vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    
	return Rec(a,n-1,0,sum,dp);
}
signed main()
{
	vector<int> a = {5, 1, 6, 11};
	int n = a.size();
	
	cout<< MinimumAbsDiff(a,n) <<endl;
	
	return 0;
}
