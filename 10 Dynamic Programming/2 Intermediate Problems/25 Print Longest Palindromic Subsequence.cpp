#include<bits/stdc++.h>
using namespace std;
void LPS(string s,int n)
{
	int dp[n+1][n+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)  dp[i][j]=0;
			
			else if(s[i-1] == s[n-j])  dp[i][j] = dp[i-1][j-1] + 1;
			
			else  dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
		}
	}
	int i=n,j=n;
	
	string s3(dp[n][n],'\n');
	
	int ind = dp[n][n];
	
	while(i !=0 && j != 0)
	{
		if(s[i-1] == s[n-j])
		{
			s3[--ind] = s[i-1];
			i--;
			j--;
		}
		
		else if(dp[i-1][j] > dp[i][j-1])
		i--;
		
		else
		j--;
	}
	
	cout<< s3 <<endl;
}
signed main()
{
	string s = "GEEKSFORGEEKS";
	int n = s.length();
    
    LPS(s,n);
    
	return 0;
}
