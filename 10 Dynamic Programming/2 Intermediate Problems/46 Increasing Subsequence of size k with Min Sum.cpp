#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int n,int k)
{
	vector<vector<int>> dp(k,vector<int>(n,INT_MAX));
	    
    for(int i=0;i<k;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i==0)
            dp[i][j]=a[j];
            
			else
            for(int l=i-1;l<j;l++)
            {
                if(a[l]<a[j] && dp[i-1][l] != INT_MAX)
                dp[i][j] = min(dp[i][j] , dp[i-1][l] + a[j]);
            }
            
        }
    }
    int ans = *min_element(dp[k-1].begin(),dp[k-1].end());
    
    return ((ans!=INT_MAX)?ans:-1);
}
signed main()
{
	int a[] = { 58, 12, 11, 12, 82, 30, 20, 77, 16, 86 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;
    
    cout << solve(a, n, k) << endl;
    return 0;
}
