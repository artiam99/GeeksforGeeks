#include<bits/stdc++.h>
using namespace std;
int LPS(string s,int n)
{
	int dp[2][n];
    
        for(int i = n - 1 ; i >= 0 ; i--)
        for(int j = i ; j < n ; j++)
        {
            if(i == j) dp[i%2][j] = 0;
            
            else
            {
                if(s[i] == s[j])
                dp[i%2][j] = min( ((i+1 < j-1) ? dp[1-i%2][j-1] : 0) , min( dp[1-i%2][j] + 1 , dp[i%2][j-1] + 1 ) );
                
                else
                dp[i%2][j] = min(dp[1-i%2][j] + 1 , dp[i%2][j-1] + 1 );
            }
        }
    return n - dp[0][n-1];
}
signed main()
{
	string s = "GEEKSFORGEEKS";
	int n = s.length();
    
    cout<< LPS(s,n) <<endl;
    
	return 0;
}
