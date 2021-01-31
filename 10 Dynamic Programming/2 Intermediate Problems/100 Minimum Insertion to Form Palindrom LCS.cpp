#include<bits/stdc++.h>
using namespace std;
int MinInsertion(string s)
{
	int n = s.length();
	
	int dp[2][n+1];
    
    for(int i = 0 ; i <= n ; i++)
    for(int j = 0 ; j <= n ; j++)
    {
        if(i == 0 || j == 0) dp[i%2][j] = 0;
        
        else if(s[i-1] == s[n - j])
        dp[i%2][j] = dp[1-i%2][j-1] + 1;
            
        else
        dp[i%2][j] = max( dp[1-i%2][j] , dp[i%2][j-1] );
    }
    return n - dp[n%2][n];
}
signed main()
{
	string s = "geeks";
	
	cout<< MinInsertion(s) <<endl;
	
	return 0;
}
