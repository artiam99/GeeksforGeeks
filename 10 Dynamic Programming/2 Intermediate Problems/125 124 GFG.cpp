#include<bits/stdc++.h>
using namespace std;
int MaxLen(string s1,int n1,string s2,int n2)
{
	int dp[n2+1][n1+1];
    
    int mx = 0;
    
    for(int i = 0 ; i <= n2 ; i++)
    {
	    for(int j = 0 ; j <= n1 ; j++)
	    {
	        if(i==0 || j==0) dp[i][j] = 0;
	        
	        else
	        {
	            if(s1[j-1]==s2[i-1])  dp[i][j] = dp[i-1][j-1] + 1 ;
	            
	            else  dp[i][j] = dp[i][j-1];
	        }
	    }
        mx = max(mx , dp[i][n1]);
    }
    return mx;
}
signed main()
{
	string s1 = "abcd";
	int n1 = s1.length();
	
	string s2 = "bacdbdcd";
	int n2 = s2.length();
	
	cout<< MaxLen(s1,n1,s2,n2) <<endl;
	return 0;
}
