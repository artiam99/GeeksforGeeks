#include<bits/stdc++.h>
using namespace std;
int MinSum(vector<int> &a,int n)
{
	if(n < 4)
    return *min_element(a.begin(),a.end());

    int dp[n+1];
    
    dp[0] = dp[1] = dp[2] = dp[3] = 0;
    
    for(int i = 4 ; i <= n ; i++)
    {
        dp[i] = INT_MAX;
        
        for(int j = i-3 ; j <= i ; j++)
        dp[i] = min(dp[i] , dp[j-1] + a[j-1]);
    }
    return dp[n];
}
signed main()
{
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = a.size();
	
	cout<< MinSum(a,n) <<endl;
	
	return 0;
}
