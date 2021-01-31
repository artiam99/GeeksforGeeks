#include<bits/stdc++.h>
using namespace std;
int Rec(string &s,int r,char c,int dp[][3])
{
    if(r < 0)  return 0;
    
    if(dp[r][c-'a'] != -1)  return dp[r][c-'a'];
    
    if(c == 'a')
    {
        if(s[r] == 'a')  return dp[r][c-'a'] = 1 + Rec(s,r-1,'a',dp) + Rec(s,r-1,'a',dp);
        
        else if(s[r] == 'b')  return dp[r][c-'a'] = Rec(s,r-1,'a',dp);
        
        else  return dp[r][c-'a'] = Rec(s,r-1,'a',dp);
    }
    else if(c == 'b')
    {
        if(s[r] == 'a')  return dp[r][c-'a'] = 1 + Rec(s,r-1,'a',dp) + Rec(s,r-1,'b',dp);
        
        else if(s[r] == 'b')  return dp[r][c-'a'] = Rec(s,r-1,'b',dp) + Rec(s,r-1,'b',dp);
        
        else  return dp[r][c-'a'] = Rec(s,r-1,'b',dp);
    }
    else
    {
        if(s[r] == 'a')  return dp[r][c-'a'] = Rec(s,r-1,'c',dp);
        
        else if(s[r] == 'b')  return dp[r][c-'a'] = Rec(s,r-1,'b',dp) + Rec(s,r-1,'c',dp);
        
        else  return dp[r][c-'a'] = Rec(s,r-1,'c',dp) + Rec(s,r-1,'c',dp) ;
    }
}
int CountSubSeq(string &s,int n)
{
	int ans = 0;
	
	int dp[n][3];  memset(dp,-1,sizeof(dp));
    
    for(int i = 0 ; i < n ; i++)
    if(s[i] == 'c')
    ans += Rec(s,i-1,'c',dp);
    
    return ans;
}
signed main()
{
	string s = "abcabc";
	int n = s.length();
	
	cout<< CountSubSeq(s,n) <<endl;
	
	return 0;
}
