#include<bits/stdc++.h>
using namespace std;
int MaximumSubset(vector<int> &a,int n)
{
	sort(a.begin(),a.end());
	
	vector<int> dp(n,1);
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		if(a[i]%a[j]==0)
		dp[i]=max(dp[i],dp[j]+1);
	}
	
	return *max_element(dp.begin(),dp.end());
}
signed main()
{
	vector<int> a={18, 1, 3, 6, 13, 17};
	int n=a.size();
	
	cout<< MaximumSubset(a,n);
	    
	return 0;
}
