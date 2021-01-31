#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &a,int n,int yr,int l,int r,vector<vector<bool>> &step,vector<vector<int>> &dp)
{
	if(l == r)
	{
		step[l][r] = 0;
		
		return a[l] * yr;
	}
	
	if(dp[l][r] != -1)  return dp[l][r];
	
	int b = a[l]*yr + Rec(a , n , yr+1 , l+1 , r , step , dp);
	
	int e = a[r]*yr + Rec(a , n , yr+1 , l , r-1 , step , dp);
	
	if(b > e)  step[l][r] = 0;
	
	else  step[l][r] = 1;
	
	return dp[l][r] = max(b , e);
}
int MaxProfit(vector<int> &a,int n)
{
	vector<vector<int>> dp(n,vector<int>(n,-1));
	
	vector<vector<bool>> step(n,vector<bool>(n));
		
	int ans = Rec(a,n,1,0,n-1,step,dp);
	
	int i = 0 , j = n-1;
	
	while(i <= j)
	{
		if(step[i][j] == 0)
		{
			cout<< "Beg ";
			
			i++;
		}
		else if(step[i][j] == 1)
		{
			cout<< "End ";
			j--;
		}
	}
	cout<<endl;
	
	return ans;
}
signed main()
{
	vector<int> a = {2, 4, 6, 2, 5};
	int n = a.size();
	
	cout<< MaxProfit(a,n) <<endl;
    
	return 0;
}
