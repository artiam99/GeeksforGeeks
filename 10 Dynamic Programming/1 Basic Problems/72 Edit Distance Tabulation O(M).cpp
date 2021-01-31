#include<bits/stdc++.h>
using namespace std;
int MinStep(string s1,int n1,string s2,int n2)
{
	vector<vector<int>> dp(2,vector<int>(n2+1));
	
	for(int i=0;i<=n1;i++)
	for(int j=0;j<=n2;j++)
	{
		if(i==0 || j==0)  dp[i%2][j] = max(i,j);
		
		else if(s1[i-1] == s2[j-1])  dp[i%2][j] = dp[1-i%2][j-1];
		
		else  dp[i%2][j] = 1 + min(dp[1-i%2][j-1] , min(dp[i%2][j-1] , dp[1-i%2][j]));
	}
	
	return dp[n1%2][n2];
}
signed main()
{
	string s1 = "geek";
	string s2 = "gesek";
	
	cout<< MinStep(s1 , s1.length()-1 , s2 , s2.length()-1) <<endl;
    
	return 0;
}
