#include<bits/stdc++.h>
using namespace std;
int RepeatedDelete(string &s,int n)
{
    int dp[n][n];
    
    for(int i = n-1 ; i >= 0 ; i--)
    {
        for(int j = i ; j < n ; j++)
        {
             if(i==j) dp[i][j] = 1;
             
             else
             {
                int case1 = dp[i+1][j] + 1;
                 
                int case2 = INT_MAX;
                 
                for(int k = i+1 ; k <= j ; k++)
                if(s[k] == s[i])
                case2 = min(case2 , ((i+1 == k) ? 1 : dp[i+1][k-1]) + ((k+1 > j) ? 0 : dp[k+1][j]));
                 
                dp[i][j] = min(case1 , case2);
             }
        }
    }
    return dp[0][n-1];
}
signed main()
{
	string s = "2553432";
	int n = s.length();
	
	cout<< RepeatedDelete(s,n) <<endl;
	
	return 0;
}
