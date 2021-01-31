#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int subsequenceCount(string s, string t)
{
    int dp[t.length() + 1][s.length() + 1]; 
  
    for (int i = 0; i <= t.length(); i++) 
    for (int j = 0; j <= s.length(); j++)
    {
        if(i==0)  dp[i][j]=1;
        
        else if(j==0)  dp[i][j]=0;
        
        else if (t[i - 1] == s[j - 1]) 
        dp[i][j] = (dp[i][j - 1] % mod + dp[i - 1][j - 1] % mod) % mod; 
  
        else
        dp[i][j] = dp[i][j - 1]; 
    } 
 
    return dp[t.length()][s.length()]; 
} 
signed main()
{
	string s = "geeksforgeeks";
	string t = "ge" ;
	
	cout<< subsequenceCount(s,t) <<endl;
    
	return 0;
}
