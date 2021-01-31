#include<bits/stdc++.h>
using namespace std;
int MinStep(string s1,int n1,string s2,int n2)
{
	vector<vector<int>> dp(n1+1,vector<int>(n2+1));
	
	for(int i=1;i<=n1;i++)
	dp[i][0] = i;
	
	for(int i=1;i<=n2;i++)
	dp[0][i] = i;
	
	for(int i=1;i<=n1;i++)
	for(int j=1;j<=n2;j++)
	{
		if(s1[i-1] == s2[j-1])
		dp[i][j] = dp[i-1][j-1];
		
		else
		{
			int ins = dp[i-1][j];
			int rem = dp[i][j-1];
			int rep = dp[i-1][j-1];
			
			dp[i][j] = 1 + min(ins , min(rem , rep));
		}
	}
	return dp[n1][n2];
}
signed main()
{
	string s1 = "geek";
	string s2 = "gesek";
	
	cout<< MinStep(s1 , s1.length()-1 , s2 , s2.length()-1) <<endl;
    
	return 0;
}
