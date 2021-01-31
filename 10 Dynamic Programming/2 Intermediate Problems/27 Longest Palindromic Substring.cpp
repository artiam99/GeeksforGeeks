#include<bits/stdc++.h>
using namespace std;
void LPSstr(string s,int n)
{
    bool dp[2][n];  memset(dp,0,sizeof(dp)); // Longest Reverse Diagonal that cuts the main diagonal
	    
    int mx=0;
    int l=0,r=0;
    
    for(int i=n-1;i>=0;i--)
    for(int j=i;j<n;j++)
    {
        if(i==j)  dp[i%2][j] = true;
        
        else if(s[i]==s[j] && (j-1<i+1 || dp[1-i%2][j-1]))
        {
            dp[i%2][j]=true;
            
            if(mx<=j-i+1)
            {
                mx=j-i+1;
                l=i;r=j;
            }
        }
        
        else dp[i%2][j]=false;
    }
    
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
