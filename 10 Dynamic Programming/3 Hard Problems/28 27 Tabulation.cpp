#include<bits/stdc++.h>
using namespace std;
int No_of_Arrays(int n,int m)
{
	int dp[n+1][m+1];
	    
    vector<int> in[m+1];
    
    for(int i = 1 ; i <= m ; i++)
    for(int j = 1 ; j <= m ; j++)
    if((i > j && i % j == 0) || (i <= j && j % i ==0))
    in[i].push_back(j);
    
    for(int i = 0 ; i <= n ; i++)
    for(int j = 1 ; j <= m ; j++)
    {
        if(i == 0)  dp[i][j] = 1;
        
        else
        {
            dp[i][j] = 0;
            
            for(auto k : in[j])
            dp[i][j] += dp[i-1][k];
        }
    }
    
    return dp[n][1];
}
signed main()
{
	int n = 3 , m = 3;
	
	cout<< No_of_Arrays(n,m) <<endl;
    
	return 0;
}
