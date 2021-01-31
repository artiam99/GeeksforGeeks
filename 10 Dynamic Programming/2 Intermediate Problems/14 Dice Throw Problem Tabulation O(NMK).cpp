#include<bits/stdc++.h>
using namespace std;
int NumberofWays(int n , int m , int x)
{
    long long dp[2][x+1];
        
    for(int i=0;i<=n;i++)
    for(int j=0;j<=x;j++)
    {
        if(i==0 && j==0)  dp[i%2][j] = 1;
        
        else if(i==0 || j==0)  dp[i%2][j] =0;
        
        else
        {
            dp[i%2][j] = 0;
            for(int k=1 ; k <= min(j,m) ; k++)
            dp[i%2][j] += dp[1-i%2][j-k];
            
        }
    }
    return dp[n%2][x];
}
signed main()
{
	int n = 3 , m = 6 , x = 12; // n dice m faces with numbers 1 to m .. Find no of ways to find x 
	
	cout<< NumberofWays(n,m,x) <<endl;
    
	return 0;
}

