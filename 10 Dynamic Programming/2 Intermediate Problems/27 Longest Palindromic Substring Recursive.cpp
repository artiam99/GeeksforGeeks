#include<bits/stdc++.h>
using namespace std;
void Rec(string &s,int i,int j,vector<vector<int>> &dp,int &mx,int &l,int &r)
{
    if(i>j)
    {
        dp[i][j]=0;
        return;
    }
    
    if(i==j)
    {
        dp[i][j]=1;
        return;
    }
    
    if(dp[i][j]!=-1)
    return;
    
    Rec(s,i+1,j,dp,mx,l,r);
    Rec(s,i,j-1,dp,mx,l,r);
    
    if(s[i]==s[j] && (j-1<i+1 || dp[i+1][j-1]))
    {
        if(mx<=j-i+1)
        {
            mx=j-i+1;
            l=i;
            r=j;
        }
        dp[i][j] = 1;
    }
    else
    dp[i][j] = 0;
}
void LPSstr(string s,int n)
{
    vector<vector<int>> dp(n,vector<int>(n,-1));
	    
    int mx=0;
    int l=0,r=0;
    
    Rec(s,0,n-1,dp,mx,l,r);
    
    for(int i=l;i<=r;i++)  cout<<s[i];
    cout<<endl;
}
signed main()
{
	string s = "aaaabbaa";
	int n = s.length();
    
    LPSstr(s,n);
    
	return 0;
}
