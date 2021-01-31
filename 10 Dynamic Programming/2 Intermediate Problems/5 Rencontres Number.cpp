#include<bits/stdc++.h>
using namespace std;
int Rencontres(int n,int m)
{
	int C[m+1];
	
	memset(C,0,sizeof(C));
	C[0] = 1;
	
	
	for(int i=0;i<n;i++)
	for(int j=min(i,m)+1;j>0;j--)
	C[j]+=C[j-1];
	
	n -= m;
	int dp[n+1];
	
	dp[0]=1;
	dp[1]=0;
	dp[2]=1;
	
	for(int i=3;i<=n;i++)
	dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
	
	return dp[n] * C[m];
}
signed main()
{
	int n = 7 , m = 2;
	
	cout<< Rencontres(n , m) <<endl;
    
	return 0;
}

