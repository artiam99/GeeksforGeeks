#include<bits/stdc++.h>
using namespace std;
int LCSK(string s1,int n1,string s2,int n2,int K)
{
	int dp[n1+1][n2+1][K+1];
	
	for(int k = 0 ; k <= K ; k++)
	for(int i = 0 ; i <= n1 ; i++)
	for(int j = 0 ; j <= n2 ; j++)
	{
		if(k == 0) dp[i][j][k] = 0;
		
		else if(i==0 || j==0) dp[i][j][k] = 10000000;
		
		else
		{
			int cost = ((s1[i-1] - 'a') ^ (s2[j-1] - 'a')); // Cost for Conversion
			
			dp[i][j][k] = min({cost + dp[i-1][j-1][k-1] , dp[i-1][j][k] , dp[i][j-1][k]});
		}
	}
	return dp[n1][n2][K];
}
signed main()
{
	string s1 = "abble";
	int n1 = s1.length();
	
	string s2 = "pie";
	int n2 = s2.length();
	
	int K = 2;
	
	cout<< LCSK(s1,n1,s2,n2,K) <<endl;
	
	return 0;
}
