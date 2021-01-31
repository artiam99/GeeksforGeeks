#include<bits/stdc++.h>
using namespace std;
int maxTasks(int hi[],int lo[],int n)
{
	int dp[2][3];
	
	dp[0][0] = hi[0] ; dp[0][1] = lo[0] ; dp[0][2] = 0;
	
	for(int i=1;i<n;i++)
	{
		dp[i%2][0] = hi[i] + dp[1-i%2][2];
		
		dp[i%2][1] = lo[i] + max(dp[1-i%2][0], max(dp[1-i%2][1] , dp[1-i%2][2]));
		
		dp[i%2][2] = max(dp[1-i%2][0], max(dp[1-i%2][1] , dp[1-i%2][2]));
	}
	
	return max(dp[1-n%2][0], max(dp[1-n%2][1] , dp[1-n%2][2]));
}
signed main()
{
	int n = 5;
    int high[] = {3, 6, 8, 7, 6};
    int low[] = {1, 5, 4, 5, 3};
    
    cout << maxTasks(high, low, n) <<endl;
    
	return 0;
}
