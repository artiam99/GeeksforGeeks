#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int Fibo(int n)
{
	vector<int> dp(n+1);
	dp[0]=0;
	dp[1]=1;
	
	for(int i=2;i<=n;i++)
	dp[i]=(dp[i-1]%mod +dp[i-2]%mod)%mod;
	
	return dp[n];
}
signed main()
{
    int n=5;
    
    cout<< Fibo(n) <<endl;
    
	return 0;
}
