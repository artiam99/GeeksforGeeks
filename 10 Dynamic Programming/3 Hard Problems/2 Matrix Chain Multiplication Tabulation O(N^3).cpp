#include<bits/stdc++.h>
using namespace std;
int MinMultiplication(vector<int> &a,int n)
{	
	int dp[n-1][n-1];
	
	for(int i = n-2 ; i >= 1 ; i--)
	{
		for(int j = i ; j <= n-2 ; j++)
		{
			dp[i][j] = INT_MAX;
			
			for(int k = i ; k <= j ; k++)
			dp[i][j] = min(dp[i][j] , ((i > k-1) ? 0 : dp[i][k-1]) + ((k+1 > j) ? 0 : dp[k+1][j]) + a[i-1] * a[k] * a[j+1]);
		}
	}
	return dp[1][n-2];
}
signed main()
{
	vector<int> a = {40 , 20 , 30 , 10 , 30};
	int n = a.size();
	
	cout<< MinMultiplication(a,n) <<endl;
    
	return 0;
}
