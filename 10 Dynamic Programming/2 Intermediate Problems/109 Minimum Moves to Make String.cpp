#include<bits/stdc++.h>
using namespace std;
int MinMoves(string s,int n)
{
	int dp[n];
	
	dp[0] = 1;
	
	for(int i = 1 ; i < n ; i++)
	{
		dp[i] = dp[i-1] + 1;
		
		if(i&1)
		{
			bool flag = 1;
			
			for(int j = 0 ; j <= i/2 ; j++)
			if(s[j] != s[i/2 + 1 + j])
			{
				flag = 0;
				break;
			}
			
			if(flag)
			dp[i] = min( dp[i] , dp[i/2] + 1);
		}
	}
	return dp[n-1];
}
signed main()
{
	string s = "aaaaaaaa";
	int n = s.length();
	
	cout<< MinMoves(s,n) <<endl;
	
	return 0;
}
