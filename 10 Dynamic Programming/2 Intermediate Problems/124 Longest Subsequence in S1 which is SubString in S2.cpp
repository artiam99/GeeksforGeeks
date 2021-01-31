#include<bits/stdc++.h>
using namespace std;
int MaxLen(string s1,int n1,string s2,int n2)
{
	int dp[n1+1][n2+1][2];
    
    for(int i = 0 ; i <= n1 ; i++)
    for(int j = 0 ; j <= n2 ; j++)
    {
        if(i==0 || j==0) dp[i][j][0] = dp[i][j][1] = 0;
        
        else
        {
            if(s1[i-1]==s2[j-1])  dp[i][j][1] = dp[i-1][j-1][1] + 1 ;
            
            else  dp[i][j][1] = dp[i-1][j][1];
                
            dp[i][j][0] = max( max(dp[i-1][j][0] , dp[i-1][j][1]) , max(dp[i][j-1][0] , dp[i][j-1][1]));
        }
    }
    return max(dp[n1][n2][0] , dp[n1][n2][1]);
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
