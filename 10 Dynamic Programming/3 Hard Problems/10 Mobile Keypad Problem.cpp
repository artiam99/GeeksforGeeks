#include<bits/stdc++.h>
using namespace std;
long long GetCount(int N)
{
	long long dp[2][10];
	
	for(int i = 0 ; i < N ; i++)
	{
	    for(int j = 0 ; j <= 9 ; j++)
	    {
	        if(i == 0)  dp[i%2][j] = 1;
	        
	        else
	        {
	            if(j == 0)  dp[i%2][j] = dp[1-i%2][0] + dp[1-i%2][8];
	            
	            else if(j == 1)  dp[i%2][j] = dp[1-i%2][1] + dp[1-i%2][2] + dp[1-i%2][4];
	            
	            else if(j == 2)  dp[i%2][j] = dp[1-i%2][2] + dp[1-i%2][1] + dp[1-i%2][3] + dp[1-i%2][5];
	            
	            else if(j == 3)  dp[i%2][j] = dp[1-i%2][3] + dp[1-i%2][2] + dp[1-i%2][6];
	            
	            else if(j == 4)  dp[i%2][j] = dp[1-i%2][4] + dp[1-i%2][1] + dp[1-i%2][5] + dp[1-i%2][7];
	            
	            else if(j == 5)  dp[i%2][j] = dp[1-i%2][5] + dp[1-i%2][2] + dp[1-i%2][4] + dp[1-i%2][6] + dp[1-i%2][8];
	            
	            else if(j == 6)  dp[i%2][j] = dp[1-i%2][6] + dp[1-i%2][3] + dp[1-i%2][5] + dp[1-i%2][9];
	            
	            else if(j == 7)  dp[i%2][j] = dp[1-i%2][7] + dp[1-i%2][4] + dp[1-i%2][8];
	            
	            else if(j == 8)  dp[i%2][j] = dp[1-i%2][8] + dp[1-i%2][5] + dp[1-i%2][7] + dp[1-i%2][9] + dp[1-i%2][0];
	            
	            else if(j == 9)  dp[i%2][j] = dp[1-i%2][9] + dp[1-i%2][6] + dp[1-i%2][8];
	        }
	    }
	}
	long long ans = 0;
	
	for(int i = 0 ; i <= 9 ; i++)
	ans += dp[1-N%2][i];
	
	return ans;
}
signed main()
{
	int N = 2;
	
	cout<< GetCount(N) <<endl;
    
	return 0;
}
