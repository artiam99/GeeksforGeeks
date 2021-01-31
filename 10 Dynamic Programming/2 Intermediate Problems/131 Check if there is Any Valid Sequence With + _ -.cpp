#include<bits/stdc++.h>
using namespace std;
bool Rec(vector<int> &a,int n,int i,int M,int sum,vector<vector<int>> &dp)
{
	if(i < 0)
	return (sum % M == 0);
	
	if(dp[i][sum % M] != -1)  return dp[i][sum % M];
	
	return dp[i][sum % M] = (Rec(a,n,i-1,M,sum,dp) || ((sum >= 2*a[i]) ? Rec(a,n,i-1,M,sum-2*a[i],dp) : false));
}
bool check(vector<int> &a,int n,int M)
{
	int sum = accumulate(a.begin(),a.end(),0);
	
	if(sum % M == 0)  return true;
	
	if(sum < M)  return false;
	
	vector<vector<int>> dp(n,vector<int>(M,-1));
	
	return Rec(a,n,n-1,M,sum,dp);
}
signed main()
{
	vector<int> a = {1,2,3,4,6};
	int n = a.size();
	
	int M = 4;
	
	if(check(a,n,M))  cout<< "Sequence Found" <<endl;
	
	else  cout<< "Sequence Not Found" <<endl;
	
	return 0;
}
