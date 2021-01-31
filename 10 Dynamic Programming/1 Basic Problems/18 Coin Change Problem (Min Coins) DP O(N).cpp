#include<bits/stdc++.h>
using namespace std;
int MinCoin(vector<int> &a,int m,int n)
{
	vector<int> dp(n+1,INT_MAX);
	dp[0]=0;
	
	for(int i=0;i<m;i++)
	{
		for(int j=a[i];j<=n;j++)
		{
			if(dp[j-a[i]]!=INT_MAX)
			dp[j]=min(dp[j],dp[j-a[i]]+1);
		}
	}
	return dp[n];
}
signed main()
{
    vector<int> a={2,1};
    int m=a.size();
    
    int n=7;
    
    cout<< MinCoin(a,m,n) <<endl;
    
	return 0;
}
