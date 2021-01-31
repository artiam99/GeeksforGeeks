#include<bits/stdc++.h>
using namespace std;
void SOP(int n)
{
	int dp[2][n+1];
	
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= n ; j++)
		{
			if(j == 0)  dp[i%2][j] = 0;
		
			else if(i == 1)  dp[i%2][j] = j + dp[i%2][j-1];
		
			else
			dp[i%2][j] = dp[i%2][j-1] + j * (dp[1-i%2][n] - dp[1-i%2][j]);
		}
		cout<< dp[i%2][n] <<endl;
	}
}
signed main()
{
	int N = 5;
	
	SOP(N);
	
	return 0;
}
