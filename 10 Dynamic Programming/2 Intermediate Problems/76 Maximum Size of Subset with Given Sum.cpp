#include<bits/stdc++.h>
using namespace std;
int MaxSubsetSize(vector<int> &a,int n,int k)
{
	int dp[2][k+1];
	
	for(int i=0;i<=n;i++)
	for(int j=0;j<=k;j++)
	{	
		if(j==0) dp[i%2][j] = 1;
		
		else if(i==0) dp[i%2][j] = 0;
		
		else  dp[i%2][j] = max(dp[1-i%2][j] , ( (j >= a[i-1] && dp[1-i%2][j-a[i-1]]) ? dp[1-i%2][j-a[i-1]] + 1 : 0)); 
	}
	return dp[n%2][k] - 1;
}
signed main()
{
	vector<int> a = {2, 3, 5, 7, 10, 15};
	int n = a.size();
	
	int k = 10;
	
	cout<< MaxSubsetSize(a,n,k) <<endl;
    
	return 0;
}
