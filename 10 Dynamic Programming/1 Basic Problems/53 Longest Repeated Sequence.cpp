#include<bits/stdc++.h>
using namespace std;
void LRS(string s,int n)
{
	int dp[n+1][n+1];
	
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	{
		if(i == 0 || j == 0)  dp[i][j] = 0;
		
		else if(i != j && s[i-1] == s[j-1])  dp[i][j] = dp[i-1][j-1] + 1;
		
		else  dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
	}
		
	int i=n,j=n;
	
	string fs;
	
	while(i!=0 && j!=0)
	{
		if(i != j && s[i-1] == s[j-1])
		{
			fs +=s[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
		i--;
		else
		j--;
	}
	
	reverse(fs.begin(),fs.end());
	
	cout<<fs<<endl;
}
signed main()
{
	string s = "AABEBCDD";
	int n = s.length();
    
    LRS(s,n);
    
	return 0;
}
