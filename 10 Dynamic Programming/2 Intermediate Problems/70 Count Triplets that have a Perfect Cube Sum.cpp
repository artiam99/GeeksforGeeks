#include<bits/stdc++.h>
using namespace std;
int CountTriplets(vector<int> &a,int n)
{
	int dp[n][5001];
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 1 ; j < 5001 ; j++)
	dp[i][j] = ( (i > 0) ? dp[i-1][j] : 0) + (a[i] == j);
	
	int ans = 0;
	
	for(int i = 0 ; i < n - 2 ; i++)
	for(int j = i + 1 ; j < n - 1 ; j++)
	for(int k = 1 ; k <= 24 ; k++)
	{
		int cube = k*k*k;
		
		int rem = cube - a[i] - a[j];
		
		if(rem <= 5000)
		ans += dp[n-1][rem] - dp[j][rem];
	}
	return ans;
}
signed main()
{
	vector<int> a = {2, 5, 1, 20, 6};  // 1 <= a[i] <= 5000
	int n = a.size();
	
	cout<< CountTriplets(a,n) <<endl;
    
	return 0;
}
