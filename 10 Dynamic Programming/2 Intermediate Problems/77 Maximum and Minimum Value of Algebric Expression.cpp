#include<bits/stdc++.h>
using namespace std;
void MaxMinAlgeb(vector<int> &a,int n,int m)
{
	int sum = accumulate(a.begin(),a.end(),0);
	
	int x = min(n , m);
	
	int dp[x+1][sum+1];  memset(dp,0,sizeof(dp));
	
	dp[0][0] = 1;
	
	for(int i = 0 ; i < n + m ; i++)
	{
		for(int j = min(x , i+1) ; j >= 1 ; j--)
		{
			for(int k = 0 ; k <= sum ; k++)
			{
				if(dp[j-1][k] && k + a[i] <= sum)
				dp[j][k+a[i]] = 1;
			}
		}
	}
	int mx = INT_MIN , mn = INT_MAX;
	
	for(int i = 1 ; i < sum ; i++)
	if(dp[x][i])
	{
		mx = max(mx , i * (sum - i));
		
		mn = min(mn , i * (sum - i));
	}
	
	cout<< mx << " " << mn <<endl;
}
signed main()
{
	vector<int> a = {1, 2, 3, 4};
	int n = 3 , m = 1;
	
	MaxMinAlgeb(a,n,m);
    
	return 0;
}
