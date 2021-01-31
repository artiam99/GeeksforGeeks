#include<bits/stdc++.h>
using namespace std;
int Rec(vector<int> &wt,vector<int> &val,int n,int k,int ind,int diff,map<pair<int,int>,int> &dp)
{
	if(ind == n)
	{
		if(diff == 0)
		return 0;
		
		return INT_MIN;
	}
	
	if(dp.find({ind,diff}) != dp.end())  return dp[{ind,diff}];
	
	return dp[{ind,diff}] = max( Rec(wt , val , n , k , ind + 1 , diff , dp) , wt[ind] + Rec(wt , val , n , k , ind + 1 , diff + wt[ind] - k * val[ind] , dp) );
}
int MaxWtkeepingratio(vector<int> &wt,vector<int> &val,int n,int k)
{
	map<pair<int,int>,int> dp;
	
	return Rec(wt,val,n,k,0,0,dp);
}
signed main()
{
	vector<int> wt = {4, 8, 9};
	
	vector<int> val = {2, 4, 6};
	
	int n = wt.size();
	
	int k = 2;
	
	cout<< MaxWtkeepingratio(wt,val,n,k) <<endl;
	
	return 0;
}
