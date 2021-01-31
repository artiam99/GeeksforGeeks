#include<bits/stdc++.h>
using namespace std;
int LCS(string s1,int n1,string s2,int n2,string s3,int n3)
{
	int dp[2][n2+1][n3+1];
	
	for(int i=0;i<=n1;i++)
	for(int j=0;j<=n2;j++)
	for(int k=0;k<=n3;k++)
	{
		if(i == 0 || j == 0 || k == 0)  dp[i%2][j][k] = 0;
		
		else if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1])  dp[i%2][j][k] = dp[1-i%2][j-1][k-1] + 1;
		
		else  dp[i%2][j][k] = max(dp[1-i%2][j][k] , max(dp[i%2][j-1][k] , dp[i%2][j][k-1]));
	}
	
	return dp[n1%2][n2][n3];
}
signed main()
{
	string s1 = "geeks";
	string s2 = "geeksfor";
	string s3 = "geeksforgeeks";
	int n1 = s1.length();
	int n2 = s2.length();
    int n3 = s3.length();
    
    cout<< LCS(s1,n1,s2,n2,s3,n3) <<endl;
    
	return 0;
}
