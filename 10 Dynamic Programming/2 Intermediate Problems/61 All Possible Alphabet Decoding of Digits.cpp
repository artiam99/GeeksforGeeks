#include<bits/stdc++.h>
using namespace std;
int NoofDecoding(string s,int n)
{
	if(s[0]==48)  return 0;
    
    int dp[n+1];  memset(dp,0,sizeof(dp));
    
    dp[0] = dp[1] = 1;
    
    for(int i=2;i<=n;i++)
    {
        if(s[i-1] == 48 && !(s[i-2] == 49 || s[i-2] == 50))  break;
        
		if(s[i-1]==48)  dp[i] = dp[i-2];
        
		else  dp[i] = dp[i-1];
        
		if(s[i-1] != 48 && s[i-2] != 48 && (s[i-2]-48)*10 + s[i-1]-48 <= 26)
        dp[i] += dp[i-2];
    }
    return dp[n];
}
signed main()
{
	string s = "1234"; // ABCD , LCD , AWD
	int n = s.length();
	
	cout<< NoofDecoding(s,n) <<endl;
    
	return 0;
}
