#include<bits/stdc++.h>
using namespace std;
int MaxSum(vector<int> &a,int n)
{
	if(n<4)  return -1;
    
    int dp[n];
    
    int mn = a[0];
    
    dp[0] = INT_MIN;
    
    for(int i = 1 ; i < n ; i++)
    {
        dp[i] = max(dp[i-1] , a[i] - mn);
        
        mn = min(mn , a[i]);
    }
    
    int mx = a[n-1];
    
    dp[n-1] = INT_MIN;
    
    int ans = INT_MIN;
    
    for(int i = n-2 ; i >= 2 ; i--)
    {
        dp[i] = max(dp[i+1] , mx - a[i]);
        
        ans = max(ans , dp[i] + dp[i-1]);
        
        mx = max(mx , a[i]);
    }
    
    return ans;
}
signed main()
{
	vector<int> a = {4, 8, 9, 2, 20};
	int n = a.size();
	
	cout<< MaxSum(a,n) <<endl;
    
	return 0;
}
