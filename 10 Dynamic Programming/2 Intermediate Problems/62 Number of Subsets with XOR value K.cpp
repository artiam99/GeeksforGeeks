#include<bits/stdc++.h>
using namespace std;
int NoofSubset(vector<int> &a,int n,int k)
{
	int m = pow( 2 , (int)log2( *max_element(a.begin() , a.end()) ) + 1) - 1;// Number with Number of Bits equal to the number of bits in Maximum Number ... So Maximum Limit XOR Value
	
	int dp[2][m+1];
	
	for(int i=0;i<=n;i++)
	for(int j=0;j<=m;j++)
	{
		if(i==0 && j == 0)  dp[i%2][j] = 1;
		
		else if(i == 0)  dp[i%2][j] = 0;
		
		else  dp[i%2][j] = dp[1-i%2][j] + dp[1-i%2][j^a[i-1]];
	}
	
	return dp[n%2][k];
}
signed main()
{
	vector<int> a = {4, 6, 9, 2};
	int n = a.size();
	
	int k = 6;
	
	cout<< NoofSubset(a,n,k) <<endl;
    
	return 0;
}
