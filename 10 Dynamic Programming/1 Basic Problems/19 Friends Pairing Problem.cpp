#include<bits/stdc++.h>
using namespace std;
int FriendsPair(int n)
{
	vector<int> dp(n+1);
	dp[0]=dp[1]=1;
	
	for(int i=2;i<=n;i++)
	dp[i] = dp[i-1] + (i-1)*dp[i-2];
	
	return dp[n];
}
signed main()
{
    int n=3;
    
    cout<< FriendsPair(n) <<endl;
    
	return 0;
}
