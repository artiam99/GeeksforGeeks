#include<bits/stdc++.h>
using namespace std;
int Max_Wt_Transformation(string &s,int n)
{
	int dp[n+1];
	
	dp[0] = 0;  dp[1] = 1;
	
	for(int i = 2 ; i <= n ; i++)
	{
		dp[i] = dp[i-1] + 1;
		
		if(s[i-1] != s[i-2])
		dp[i] = max(dp[i] , dp[i-2] + 4);
		
		else
		dp[i] = max(dp[i] , dp[i-2] - 1);
	}
	return dp[n];
}
signed main()
{
	string s = "AAB";
	int n = s.length();
	
	cout<< Max_Wt_Transformation(s,n) <<endl;
    
	return 0;
}
