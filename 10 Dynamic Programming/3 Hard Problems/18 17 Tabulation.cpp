#include<bits/stdc++.h>
using namespace std;
int MinElements(vector<int> &a,int n)
{
    int dp[n+1][n+2][n+2];
    
    for(int i = 0 ; i <= n ; i++)
    for(int j = 1 ; j <= n+1 ; j++)
    for(int k = 1 ; k <= n+1 ; k++)
    {
        if(i == 0)  dp[i][j][k] = 0;
        
        else
        {
            dp[i][j][k] = dp[i-1][j][k];
            
            if(j == n+1 || a[i-1] < a[j-1])
            dp[i][j][k] = max(dp[i][j][k] , dp[i-1][i][k] + 1);
            
            if(k == n+1 || a[i-1] > a[k-1])
            dp[i][j][k] = max(dp[i][j][k] , dp[i-1][j][i] + 1);
        }
    }
    return n - dp[n][n+1][n+1];
}
signed main()
{
	vector<int> a = {7, 8, 1, 2, 4, 6, 3, 5, 2, 1, 8, 7};
	int n = a.size();
	
	cout<< MinElements(a,n) <<endl;
    
	return 0;
}
