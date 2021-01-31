#include<bits/stdc++.h>
using namespace std;
int MaxProfit(vector<int> &a,int n,int k)
{
	int dp[k+1][n];
    int mx = 0;
    
    for(int i = 0 ; i <= k ; i++)
    {
    	int prev_diff = INT_MIN;
    	
        for(int j = 0 ; j < n ; j++)
        {
            if(i == 0 || j == 0)  dp[i][j] = 0;
            
            else
            {
                prev_diff = max(prev_diff , dp[i-1][j-1] - a[j-1]);  // dp[i][j] = dp[i-1][j=0..j-1] - a[j=0..j-1] + a[j] ... no need to check max in dp[i-1][j=0..j-1] - a[j=0..j-1]
                
                dp[i][j] = max(dp[i][j-1] , a[j] + prev_diff);
            }
        }
    }
    return dp[k][n-1];
}
signed main()
{
	vector<int> a = {10, 22, 5, 75, 65, 80};
	int n = a.size();
	
	int k = 2;
	
	cout<< MaxProfit(a,n,k) <<endl;
	
	return 0;
}
