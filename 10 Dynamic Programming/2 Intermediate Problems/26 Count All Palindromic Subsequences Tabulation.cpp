#include<bits/stdc++.h>
using namespace std;
int CountPSS(string s,int n)
{
	int dp[2][n];  memset(dp,0,sizeof(dp));
   
   for(int i=n-1;i>=0;i--)
   for(int j=i;j<n;j++)
   {
       if(i==j) dp[i%2][j]=1;
       
       else if(s[i]==s[j]) dp[i%2][j] = dp[1-i%2][j] + dp[i%2][j-1] + 1;
       
       else dp[i%2][j] = dp[1-i%2][j] + dp[i%2][j-1] - dp[1-i%2][j-1];
   }
   return dp[0][n-1];
}
signed main()
{
	string s = "GEEKSFORGEEKS";
	int n = s.length();
    
    cout<< CountPSS(s,n) <<endl;
    
	return 0;
}
