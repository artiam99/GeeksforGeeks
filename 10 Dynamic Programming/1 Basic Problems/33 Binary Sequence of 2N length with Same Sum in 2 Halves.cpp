#include<bits/stdc++.h>
using namespace std;
int BinarySequence(int n)
{
	vector<int> dp(n+1);// Nth Line in Pascal's Triange
	dp[0]=1;
	
	for(int i=1;i<=n;i++)
	for(int j=i;j>0;j--)
	dp[j]+=dp[j-1];
	
	int res=0;
	
	for(int i=0;i<=n;i++)
	res+=dp[i]*dp[i];
	
	return res;
}
signed main()
{
	int n=2;
	
	cout<< BinarySequence(n) <<endl;
	    
	return 0;
}
