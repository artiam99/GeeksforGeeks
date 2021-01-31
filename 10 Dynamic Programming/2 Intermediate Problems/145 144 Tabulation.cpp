#include<bits/stdc++.h>
using namespace std;
int MinimumAbsDiff(vector<int> &a,int n)
{
	int sum = accumulate(a.begin(),a.end(),0);
	    
	int dp[n+1][sum+1];
	    
    for(int i = 0 ; i <= n ; i++)
    for(int j = 0 ; j <= sum ; j++)
    {
        if(i==0)  dp[i][j] = abs(sum-2*j);
        
        else dp[i][j] = min( ((j+a[i-1] <= sum) ? dp[i-1][j+a[i-1]] : INT_MAX) , dp[i-1][j]);
    }
    return dp[n][0];
}
signed main()
{
	vector<int> a = {5, 1, 6, 11};
	int n = a.size();
	
	cout<< MinimumAbsDiff(a,n) <<endl;
	
	return 0;
}
