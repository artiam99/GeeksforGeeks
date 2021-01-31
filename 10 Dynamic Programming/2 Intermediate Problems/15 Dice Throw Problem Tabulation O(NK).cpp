#include<bits/stdc++.h>
using namespace std;
int NumberofWays(int n , int m , int x)
{
    long long dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
    
    dp[0][0] = 1;
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=x;j++)
    {
        dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
        
        if(j-m-1 >= 0)
        dp[i][j] -= dp[i-1][j-m-1];
    }
    return dp[n][x];
}
signed main()
{
	int n = 3 , m = 6 , x = 12; // n dice m faces with numbers 1 to m .. Find no of ways to find x 
	
	cout<< NumberofWays(n,m,x) <<endl;
    
	return 0;
}
/* this is observation optimization .. N = 2 , M = 4 , X =5 
                                      table
                                      0 1 2 3 4 5
									  ___________
                                   0| 1 0 0 0 0 0 
                                   1| 0 1 1 1 1 0
                                   2| 0 0 1 2 3 4
                                      
                                      Rec(2,4,4) = Rec(1,4,3) + Rec(1,4,2) + Rec(1,4,1) + Rec(1,4,0)
                                      
                                      Rec(2,4,3) = Rec(1,4,2) + Rec(1,4,1) + Rec(1,4,0)
                                      
                                      So Rec(2,4,4) = Rec(2,4,3) + Rec(1,4,3)  ... dp[i][j] = dp[i][j-1] + dp[i-1][j-1]
                                      
                                      if(j >= m+1) Like Rec(1,4,5) = Rec(0,4,4) + Rec(0,4,3) + Rec(0,4,2) + Rec(0,4,1) + Rec(0,4,0)
                                                                                                                             5 >= m+1 but max limit is m we can't have m+1
																															 So Substract it
																															 In Recursion it's previous states are removed by dp[i][j-1] 
*/

