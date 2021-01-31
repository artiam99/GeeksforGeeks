#include<bits/stdc++.h>
using namespace std;
int MaxCoin(vector<vector<char>> &a,int n)
{
	int dp[n][n];
	
	int mx = 0;
	
	for(int i=0;i<n;i++)
	{
		if(i&1)
		for(int j=n-1;j>=0;j--)
		{
			if(a[i][j] == '#')  dp[i][j] = 0;
			
			else
			dp[i][j] = max ( ( (i > 0) ? dp[i-1][j] : 0 ) , ( (j < n-1) ? dp[i][j+1] : 0 ) ) + ( (a[i][j] == 'C') ? 1 : 0 );
			
			if(!(i==0 && j==0))
			if((i == 0 || (i > 0 && a[i-1][j] == '#')) && (j == n-1 || (j < n-1 && a[i][j+1]=='#')) && dp[i][j] == 1)
			dp[i][j] = 0;
			
			mx = max(mx , dp[i][j]);
		}
		
		else
		for(int j=0;j<n;j++)
		{
			if(a[i][j] == '#')  dp[i][j] = 0;
			
			else
			dp[i][j] = max( ( (i > 0) ? dp[i-1][j] : 0 ) , ( (j > 0) ? dp[i][j-1] : 0 ) ) + ( (a[i][j] == 'C') ? 1 : 0 );
			
			if(!(i==0 && j==0))
			if((i==0 || ( i> 0 && a[i-1][j] == '#')) && (j == 0 || (j>0 && a[i][j-1]=='#')) && dp[i][j] == 1)
			dp[i][j] = 0;
			
			mx = max(mx , dp[i][j]);
		}
	}
	
	
	return mx;
}
signed main()
{
	vector<vector<char>> a = { {'E', 'C', 'C', 'C', 'C'},
    		                   {'C', '#', 'C', '#', 'E'},
   		                       {'#', 'C', 'C', '#', 'C'},
            		           {'C', 'E', 'E', 'C', 'E'},
                		       {'C', 'E', '#', 'C', 'E'}
                		     };
    int n = a.size();
    
    cout<< MaxCoin(a,n) <<endl;
    
	return 0;
}
