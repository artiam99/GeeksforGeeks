#include<bits/stdc++.h>
using namespace std;
int LCS(string s1,int n,string s2,int m)
{
	int dp[2][m+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i == 0 || j == 0)
			dp[i%2][j] = 0;
			
			else if(s1[i-1] == s2[j-1])
			dp[i%2][j] = dp[1-i%2][j-1] + 1;
			
			else
			dp[i%2][j] = max(dp[1-i%2][j] , dp[i%2][j-1]);
		}
	}
	return dp[n%2][m];
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
