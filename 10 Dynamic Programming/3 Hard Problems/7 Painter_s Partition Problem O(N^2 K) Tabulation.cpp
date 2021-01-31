#include<bits/stdc++.h>
using namespace std;
int PaintersPartition(vector<int> &a,int n,int k)
{
	for(int i = 1 ; i < n ; i++)
	a[i] += a[i-1];
	
	int dp[n+1][k+1];
	    
    for(int i = n ; i >= 0 ; i--)
    for(int j = 1 ; j <= min(k , n-i) ; j++)
    {
        if(i == n)  dp[i][j] = INT_MIN;
        
        else if(j == 1)  dp[i][j] = a[n-1] - ((i == 0) ? 0 : a[i-1]);
        
        else
        {
            dp[i][j] = INT_MAX;
            
            for(int l = i ; l <= n-j ; l++)
            dp[i][j] = min(dp[i][j] , max( a[l] - ((i == 0) ? 0 : a[i-1]), dp[l+1][j-1]));
            
        }
    }
	return dp[0][k];   
}
signed main()
{
	vector<int> a = {12, 34, 67, 90};
	int n = a.size();
	
	int k = 2;
	
	cout<< PaintersPartition(a,n,k) <<endl;
    
	return 0;
}
