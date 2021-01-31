#include<bits/stdc++.h>
using namespace std;
int MinInsertion(string s)
{
	int dp[2][s.length()];
    
    for(int i = s.length() - 1 ; i >= 0 ; i--)
    for(int j = i ; j < s.length() ; j++)
    {
        if(i == j) dp[i%2][j] = 0;
        
        else
        {
            if(s[i] == s[j])
            dp[i%2][j] = min( ((i+1 < j-1) ? dp[1-i%2][j-1] : 0) , min( dp[1-i%2][j] + 1 , dp[i%2][j-1] + 1 ) );
            
            else
            dp[i%2][j] = min( dp[1-i%2][j] + 1 , dp[i%2][j-1] + 1 );
        }
    }
    return dp[0][s.length()-1];
}
signed main()
{
	string s = "geeks";
	
	cout<< MinInsertion(s) <<endl;
	
	return 0;
}
