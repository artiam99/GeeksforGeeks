#include<bits/stdc++.h>
using namespace std;
int count(int n,int m)
{
	vector<int> dp(n+1);
	dp[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		if(i==m)
		dp[i] = 2;
		
		else
		dp[i] = dp[i-1] + ((i>m)?dp[i-m]:0);
	}
	return dp[n];
}
signed main()
{
    int n=4,m=2;// n*m floor 1*m tile
    
    cout<< count(n,m) <<endl;
    
	return 0;
}
