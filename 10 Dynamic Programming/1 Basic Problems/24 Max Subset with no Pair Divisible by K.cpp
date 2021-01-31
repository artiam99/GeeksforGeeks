#include<bits/stdc++.h>
using namespace std;
int MaximumSubset(vector<int> &a,int n,int k)
{
	vector<int> dp(k);
	
	for(auto i:a)
	dp[i%k]++;
	
	if(k%2==0)
	dp[k/2]=min(dp[k/2],1);
	
	int res=min(dp[0],1);
	
	for(int i=1;i<=k/2;i++)
	res+=max(dp[i],dp[k-i]);
	
	return res;
}
signed main()
{
	vector<int> a={3, 7, 2, 9, 1};
	int n=a.size();
	
	int k=3;
	
	cout<< MaximumSubset(a,n,k);
	    
	return 0;
}
