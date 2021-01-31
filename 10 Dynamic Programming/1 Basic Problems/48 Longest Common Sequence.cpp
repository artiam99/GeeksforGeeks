#include<bits/stdc++.h>
using namespace std;
int LCS(string s1,int n,string s2,int m)
{
	int dp[n+1][m+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i == 0 || j == 0)
			dp[i][j] = 0;
			
			else if(s1[i-1] == s2[j-1])
			dp[i][j] = dp[i-1][j-1] + 1;
			
			else
			dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}
	return dp[n][m];
}
signed main()
{
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	int n = s1.length();
	int m = s2.length();
    
    cout<< LCS(s1,n,s2,m) <<endl;
    
	return 0;
}
