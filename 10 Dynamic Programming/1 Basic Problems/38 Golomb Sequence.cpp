#include<bits/stdc++.h>
using namespace std;
int Golomb(int n)
{
	vector<int> dp(n+1);
	dp[1]=1;
	
	for(int i=1;i<n;i++)
	dp[i+1] = 1 + dp[ i+1 - dp[dp[i]] ];
	
	for(int i=1;i<=n;i++)
	cout<< dp[i] <<" ";
	cout<<endl;
}
signed main()
{
	int n=10;
	
	Golomb(n);
    
	return 0;
}
