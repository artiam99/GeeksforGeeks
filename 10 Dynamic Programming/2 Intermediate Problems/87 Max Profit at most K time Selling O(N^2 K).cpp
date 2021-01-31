#include<bits/stdc++.h>
using namespace std;
int MaxProfit(vector<int> &a,int n,int k)
{
	int dp[k+1][n+1];
    int mx = 0;
    
    for(int i = 0 ; i <= k ; i++)
    {
        for(int j = 0 ; j <= n ; j++)
        {
            if(i==0 || j==0)  dp[i][j] = 0;
            
            else
            {
                dp[i][j] = dp[i][j-1];
                
                for(int l = i ; l < j ; l++)
                {
                	if(a[l-1] <= a[j-1])
                	dp[i][j] = max(dp[i][j] , dp[i-1][l] + a[j-1] - a[l-1]);
				}
            }
        }
        mx = max(mx , dp[i][n]);
    }
    return mx;
}
signed main()
{
	vector<int> a = {10, 22, 5, 75, 65, 80};
	int n = a.size();
	
	int k = 2;
	
	cout<< MaxProfit(a,n,k) <<endl;
	
	return 0;
}
