#include<bits/stdc++.h>
using namespace std;
int CountWay(vector<int> &a,int m,int n)
{
	vector<int> dp(n+1);
	dp[0]=1;
	
	for(int i=0;i<m;i++)
	for(int j=a[i];j<=n;j++)
	dp[j] += dp[j-a[i]];
	
	return dp[n];
}
signed main()
{
    vector<int> a={1,2,3};
    int m=a.size();
    
    int n=4;
    
    cout<< CountWay(a,m,n) <<endl;
    
	return 0;
}
