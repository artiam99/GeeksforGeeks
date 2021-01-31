#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int n,vector<int> &dp,int &mx)
{
	if(n==1)
	return 1;
	
	if(dp[n] != -1)
	return dp[n];
	
	int res,mx_curr=1;
	
	for(int i=1;i<n;i++)
	{
		res = Rec(a,i,dp,mx);
		
		if(a[i-1] < a[n-1])
		mx_curr = max(mx_curr , res + 1);
	}
	
	mx = max(mx , mx_curr);
	
	dp[n] = mx_curr;
	
	return mx_curr;
}
int LISS(vector<int> &a,int n)
{
	int mx=1;
	
	vector<int> dp(n+1,-1);
	
	Rec(a,n,dp,mx);
	
	return mx;
}
signed main()
{
	vector<int> a = {5, 8, 3, 7, 9, 1};
	int n=a.size();
    
    cout<< LISS(a,n) <<endl;
    
	return 0;
}
