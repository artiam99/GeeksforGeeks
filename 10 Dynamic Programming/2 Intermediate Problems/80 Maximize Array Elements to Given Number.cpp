#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int n,int i,int prev,int mx,vector<vector<int>> &dp)
{
	if(i == n)  return prev;
	
	if(dp[i][prev] != -2)  return dp[i][prev];
	
	int ans1 = -1 , ans2 = -1;
	
	if(prev + a[i] <= mx)  ans1 = Rec(a , n , i + 1 , prev + a[i] , mx, dp);
	
	if(prev - a[i] >= 0)  ans2 = Rec(a , n , i + 1 , prev - a[i] , mx, dp);
	
	if(ans1 == -1)  return dp[i][prev] = ans2;
	
	if(ans2 == -1)  return dp[i][prev] = ans1;
	
	return dp[i][prev] = max(ans1 , ans2);
}
int MaxNumber(vector<int> &a,int n,int g,int m)
{
	vector<vector<int>> dp(n,vector<int>(m+1 , -2));
	
	return Rec(a,n,0,g,m,dp);
}
signed main()
{
	vector<int> a = {3, 10, 6, 4, 5};
	int n = a.size();
	
	int g = 1;
	int m = 15;
	
    cout<< MaxNumber(a,n,g,m) <<endl;
    
	return 0;
}
