#include<bits/stdc++.h>
using namespace std;
int NoofWays(vector<int> &a,int n,int N)
{
	vector<int> dp(N+1);
	dp[0] = 1;
	
	for(int i=1;i<=N;i++)
	for(int j=0;j<n;j++)
	if(i >= a[j])
	dp[i] += dp[i-a[j]];
	
	return dp[N];
}
signed main()
{
	vector<int> a = {1,5,6};
	int n = a.size();
	
	int N = 7;
	
	cout<< NoofWays(a,n,N) <<endl;
	
	return 0;
}
