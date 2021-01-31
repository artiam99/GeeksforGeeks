#include<bits/stdc++.h>
using namespace std;
int MaxSquare(vector<vector<int>> &a,int n,int m)
{	
	int dp[n][m];
	
	int mx = 1;
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(i == 0 && j == 0)
			dp[i][j] = 1;
			
			else
			{
				if(a[i][j] == a[i-1][j] && a[i][j] == a[i-1][j] && a[i][j] == a[i][j-1] && a[i][j] == a[i-1][j-1])
				dp[i][j] = min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1])) + 1;
				
				else
				dp[i][j] = 1;
			}
			mx = max(mx , dp[i][j]);
		}
	}
	return mx;
}
signed main()
{
	vector<vector<int>> a = { {9, 9, 9, 8},
                			  {9, 9, 9, 6},
                 			  {9, 9, 9, 3},
                 			  {2, 2, 2, 2} };
    int n = a.size();
    int m = a[0].size();
    
    cout<< MaxSquare(a,n,m) <<endl;
	
	return 0;
}
