#include<bits/stdc++.h>
using namespace std;
int MinSquares(int m,int n)
{
	int dp[m+1][n+1];
    
    for(int i = 0 ; i <= m ; i++)
    for(int j = 0 ; j <= n ; j++)
    {
        if(i==0 || j==0)  dp[i][j] = 0;
        
        else if(i == 1)  dp[i][j] = j;
        
        else if(j == 1)  dp[i][j] = i;
        
        else
        {
            dp[i][j] = INT_MAX;
            
            for(int l = 1 ; l <= min(i,j) ; l++)
            dp[i][j] = min( dp[i][j] , 1 + min( dp[i-l][j] + dp[l][j-l] , dp[i][j-l] + dp[i-l][l] ) );
        }
    }
    return dp[m][n];
}
signed main()
{
	int m = 11 , n = 13;  // Minimum Number of Squares that can fit in M*N Rectangle  .. This is NP Hard Problem ... Above is approximate Solution ans 8 ... Exact ans is 6 -> 5 4 4 7 1 6
	
	cout<< MinSquares(m,n) <<endl;
	
	return 0;
}
