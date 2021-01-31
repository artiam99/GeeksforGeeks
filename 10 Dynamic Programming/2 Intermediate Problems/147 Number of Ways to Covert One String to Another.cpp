#include<bits/stdc++.h>
using namespace std;
int NoofWays(string s1,int n1,string s2,int n2)
{	
	int dp[2][n2+1];
	
	for(int i = 0 ; i <= n1 ; i++)
	for(int j = 0 ; j <= n2 ; j++)
	{
		if(j == 0)  dp[i%2][j] = 1;
		
		else if(i == 0)  dp[i%2][j] = 0;
		
		else
		{
			if(s1[i-1] == s2[j-1])
			dp[i%2][j] = dp[1-i%2][j-1] + dp[1-i%2][j];
			
			else
			dp[i%2][j] = dp[1-i%2][j];
		}
	}
	return dp[n1%2][n2];
}
signed main()
{
	string s1 = "aabba";
	int n1 = s1.length();
	
	string s2 = "ab";
	int n2 = s2.length();
	
	cout<< NoofWays(s1,n1,s2,n2) <<endl;
	
	return 0;
}
