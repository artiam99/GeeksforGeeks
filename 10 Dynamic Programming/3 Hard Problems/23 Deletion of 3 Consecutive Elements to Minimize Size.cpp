#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int n,int k,int l,int r,vector<vector<int>> &dp)
{
	if(l > r)  return 0;
	
	if(r-l+1 < 3)  return r-l+1;
	
	if(dp[l][r] != -1)  return dp[l][r];
	
	int ans = r-l+1;
	
	ans = min(ans , Rec(a , n , k , l , r-1 , dp) + 1);
	
	ans = min(ans , Rec(a , n , k , l+1 , r , dp) + 1);
	
	if(a[l] + k*2 == a[r])
	{
		for(int i = l+1 ; i <= r-1 ; i++)
		if(a[l] + k == a[i])
		{
			int left = Rec(a , n , k , l+1 , i-1 , dp);
			
			int right = Rec(a , n , k , i+1 , r-1 , dp);
			
			if(!left && !right)
			{
				ans = 0;
				
				break;
			}
		}
	}
	return dp[l][r] = ans;
}
int Min_Size(vector<int> &a,int n,int k)
{
	vector<vector<int>> dp(n,vector<int>(n,-1));
	
	return Rec(a,n,k,0,n-1,dp);
}
signed main()
{
	vector<int> a = {2, 3, 4, 7, 6, 4};  // Delete All a[i] , a[i+`] , a[i+2] such that a[i+1] - k = a[i] and a[i+2] - k = a[i+1]
	int n = a.size();
	
	int k = 1;
	
	cout<< Min_Size(a,n,k) <<endl;
    
	return 0;
}
