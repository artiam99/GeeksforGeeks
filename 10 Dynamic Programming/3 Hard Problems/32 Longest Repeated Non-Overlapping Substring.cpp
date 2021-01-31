#include<bits/stdc++.h>
using namespace std;
void LongestSubString(string &s,int n)
{
	int dp[2][n+1];
	    
    int mx = 0 , mxi;
    
    for(int i = 0 ; i <= n ; i++)
    for(int j = 0 ; j <= n ; j++)
    {
        if(i == 0 || j == 0)  dp[i%2][j] = 0;
        
        else if(i != j && s[i-1] == s[j-1])  dp[i%2][j] = dp[1-i%2][j-1] + 1;
        
        else  dp[i%2][j] = 0;
        
        if(mx < dp[i%2][j])
        {
            mx = dp[i%2][j];
            mxi = i;
        }
    }
    if(mx == 0)
    cout<< -1 ;
    
    else
    for(int i = mxi-mx; i <= mxi-1 ; i++)
    cout<<s[i];
    
    cout<<endl;
}
signed main()
{
	string s = "geeksforgeeks";
	int n = s.length();
	
	LongestSubString(s,n);
	
	return 0;
}
