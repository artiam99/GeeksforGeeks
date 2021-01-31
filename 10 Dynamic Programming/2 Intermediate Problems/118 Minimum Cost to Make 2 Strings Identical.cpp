#include<bits/stdc++.h>
using namespace std;
int MinCost(string s1,int n1,string s2,int n2)
{	
	int dp[n1+1][n2+1];
	
	for(int i = 0 ; i <= n1 ; i++)
	for(int j = 0 ; j <= n2 ; j++)
	{
		if(i == 0)
		{
			int cost = 0;
			
			for(int k = 0 ; k < j ; k++)
			cost += s2[k]-48;
			
			dp[i][j] = cost;
		}
		else if(j == 0)
		{
			int cost = 0;
			
			for(int k = 0 ; k < i ; k++)
			cost += s1[k]-48;
			
			dp[i][j] = cost;
		}
		else
		{
			if(s1[i-1] == s2[j-1])
			dp[i][j] = min(dp[i-1][j-1] , min( dp[i-1][j] + s1[i-1]-48 , dp[i][j-1] + s2[j-1]-48 ) );
			
			else
			dp[i][j] = min(dp[i-1][j-1] + s1[i-1]-48 + s2[j-1]-48 , min( dp[i-1][j] + s1[i-1]-48 , dp[i][j-1] + s2[j-1]-48 ) );
		}
	}
	return dp[n1][n2];
}
signed main()
{
	string s1 = "3759";
	int n1 = s1.length();
	
	string s2 = "9350";
	int n2 = s2.length();
	
	cout<< MinCost(s1,n1,s2,n2) <<endl;
	
	return 0;
}
