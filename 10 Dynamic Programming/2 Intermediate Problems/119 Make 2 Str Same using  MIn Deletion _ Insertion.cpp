#include<bits/stdc++.h>
using namespace std;
int MinCost(string s1,int n1,string s2,int n2)
{
    int dp[n1+1][n2+1];  // Same Code For only Deletion
	
	for(int i = 0 ; i <= n1 ; i++)
	for(int j = 0 ; j <= n2 ; j++)
	{
		if(i == 0)
		dp[i][j] = j;
		
		else if(j == 0)
		dp[i][j] = i;
		
		else
		{
			if(s1[i-1] == s2[j-1])
			dp[i][j] = min(dp[i-1][j-1] , min( dp[i-1][j] + 1 , dp[i][j-1] + 1 ) );
			
			else
			dp[i][j] = min(dp[i-1][j-1] + 2 , min( dp[i-1][j] + 1 , dp[i][j-1] + 1 ) );
		}
	}
	return dp[n1][n2];
}
signed main()
{
	string s1 = "heap";
	int n1 = s1.length();
	
	string s2 = "pea";
	int n2 = s2.length();
	
	cout<< MinCost(s1,n1,s2,n2) <<endl;
	
	return 0;
}
