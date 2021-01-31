#include<bits/stdc++.h>
using namespace std;
int DiffSquareSum(vector<int> &a,int n,int k)
{
	int dp[k][n];
	
	for(int i = 0 ; i < k ; i++)
	for(int j = 0 ; j < n ; j++)
	{
		if(i == 0) dp[i][j] = pow(abs(a[0] - a[j]),2);
		
		else
		{
			dp[i][j] = INT_MAX;
			
			for(int l = i ; l <= j ; l++)
			dp[i][j] = min(dp[i][j] , dp[i-1][l-1] + (int)pow(abs(a[l] - a[j]),2));
		}
	}
	return dp[k-1][n-1];
}
signed main()
{
	vector<int> a = {5, 8, 1, 10};
	int n = a.size();
	
	int k = 3;
	
	cout<< DiffSquareSum(a,n,k) <<endl;
	
	return 0;
}
