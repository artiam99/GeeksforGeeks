#include<bits/stdc++.h>
using namespace std;
int PalSstr(string s,int n)
{
    bool dp[2][n];  memset(dp,false,sizeof(dp));
    
    int cnt=0;
    
    for(int i=n-1;i>=0;i--)
    for(int j=i;j<n;j++)
    {
        if(i==j)  dp[i%2][j] = true , cnt++;
        
        else if(s[i]==s[j] && (i+1 > j-1 || dp[1-i%2][j-1])) dp[i%2][j] = true , cnt++;
        
        else dp[i%2][j]=false;
    }
   return cnt;
}
signed main()
{
	string s = "aaaabbaa";
	int n = s.length();
    
    cout<< PalSstr(s,n) <<endl;
    
	return 0;
}
