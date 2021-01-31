#include<bits/stdc++.h>
using namespace std;
double MaxAvgPart(vector<int> &a,int n,int k)
{
	int p[n+1];
	p[0] = 0;
	
	for(int i = 0 ; i < n ; i++)
	p[i+1] = p[i] + a[i];
	
	
	double dp[n];
	
	for(int i = 0 ; i < n ; i++)
	dp[i] = (p[n] - p[i]) / (n-i);
	
	for(int i = 0 ; i < k - 1 ; i++)
	{
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = i + 1 ; j < n ; j++)
			dp[i] = max(dp[i] , (p[j] - p[i]) / (double)(j - i) + dp[j]);
		}
	}
	return dp[0];
}
signed main()
{
	vector<int> a = {1, 2, 3, 4, 5, 6, 7};
	int n = a.size();
	
	int k = 4;
	
    cout<< MaxAvgPart(a,n,k) <<endl;
    
	return 0;
}
