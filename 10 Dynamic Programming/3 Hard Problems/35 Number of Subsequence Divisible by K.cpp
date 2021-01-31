#include<bits/stdc++.h>
using namespace std;
int CountSubSeq(string &s,int n,int K)
{   
    int dp[2][K];
    
    for(int i = 0 ; i < n ; i++)
    {
        if(i == 0)
        for(int j = 0 ; j < K ; j++)
        dp[i%2][j] = (j == (s[i] - 48) % K);
        
        else
        {
            for(int j = 0 ; j < K ; j++)
            dp[i%2][j] = dp[1-i%2][j];
            
            
            dp[i%2][(s[i] - 48) % K]++;
            
            for(int j = 0 ; j < K ; j++)
            dp[i%2][((j % K * 10 % K) % K + (s[i] - 48) % K) % K] += dp[1-i%2][j];
        }
    }
    return dp[1-n%2][0];
}
signed main()
{
	string s = "13074294";
	int n = s.length();
	
	int K = 5;
	
	cout<< CountSubSeq(s,n,K) <<endl;
	
	return 0;
}
