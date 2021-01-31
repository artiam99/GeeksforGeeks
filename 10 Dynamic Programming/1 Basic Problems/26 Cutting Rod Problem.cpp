#include<bits/stdc++.h>
using namespace std;
int MaximumPrice(vector<int> &a,int n)
{
	vector<int> dp=a;
	
	for(int i=1;i<n;i++)
	{
		for(int j=i/2;j<i;j++)
		dp[i] = max(dp[i], dp[j] + dp[i-j-1]);
	}
	return dp[n-1];
}
signed main()
{
	vector<int> a={1, 5, 8, 9, 10, 17, 17, 20};
	int n=a.size();
	
	cout<< MaximumPrice(a,n);
	    
	return 0;
}
