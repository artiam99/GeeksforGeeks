#include<bits/stdc++.h>
using namespace std;
int MoserdeBruijin(int n)
{
	vector<int> dp(n);
	dp[0]=0;
	dp[1]=1;
	
	for(int i=2;i<n;i++)
	{
		if(i&1)
		dp[i] = 4 * dp[i/2] +1;
		else
		dp[i] = 4 * dp[i/2];
	}
	
	for(auto i:dp)
	cout<<i<<" ";
	cout<<endl;
}
signed main()
{
	int n=10;
	
	MoserdeBruijin(n);
	
	return 0;
}
