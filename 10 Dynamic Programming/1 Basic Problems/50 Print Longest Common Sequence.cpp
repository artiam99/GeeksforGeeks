#include<bits/stdc++.h>
using namespace std;
void LCS(string s1,int n,string s2,int m)
{
	int dp[n+1][m+1];
	
	memset(dp,0,sizeof(dp));
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			dp[i][j]=0;
			
			else if(s1[i-1] == s2[j-1])
			dp[i][j] = dp[i-1][j-1] + 1;
			
			else
			dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
		}
	}
	
	int i=n,j=m;
	
	string s3;
	
	while(i !=0 && j != 0)
	{
		if(s1[i-1] == s2[j-1])
		{
			s3+=s1[i-1];
			i--;
			j--;
		}
		
		else if(dp[i-1][j] > dp[i][j-1])
		i--;
		
		else
		j--;
	}
	reverse(s3.begin(),s3.end());
	
	cout<< s3 <<endl;
}
signed main()
{
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	int n = s1.length();
	int m = s2.length();
    
    LCS(s1,n,s2,m);
    
	return 0;
}
