#include<bits/stdc++.h>
using namespace std;
int MinCost(string x, string y, int cx, int cy)
{
    int n = x.length();
	int m = y.length();
	    
    int dp[2][m+1];
    
    for(int i = 0 ; i <= n ; i++)
    for(int j = 0 ; j <= m ; j++)
    {
        if(i == 0)  dp[i%2][j] = j*cy;
        
        else if(j == 0)  dp[i%2][j] = i*cx;
        
        else
        {
            if(x[i-1] == y[j-1])
            dp[i%2][j] = min(dp[1-i%2][j-1] , min(dp[1-i%2][j] + cx , dp[i%2][j-1] + cy));
            
            else
            dp[i%2][j] = min(dp[1-i%2][j-1] + cx + cy , min( dp[1-i%2][j] + cx , dp[i%2][j-1] + cy));
            
        }
    }
    return dp[n%2][m];
}
signed main()
{
	string x = "acbd";
	string y = "abcd";
	
	int cx = 10;
	int cy = 20;
	
	cout<< MinCost(x,y,cx,cy) <<endl;
	
	return 0;
}
