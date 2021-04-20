#include<bits/stdc++.h>
using namespace std;
int MinPoints(vector<vector<int>> &a,int n,int m)
{
	int dp[n][m];

    for (int i = n-1 ; i >= 0 ; i--)
    for (int j = m-1 ; j >= 0 ; j--)
    {
        if(i == n-1 && j == m-1)  dp[i][j] = ( (a[i][j] > 0) ? 0 : abs(a[i][j]) + 1);
       
        else if(i == n-1)  dp[i][j] = max( dp[i][j+1] - a[i][j] , 0);
         
        else if(j == m-1)  dp[i][j] = max( dp[i+1][j] - a[i][j] , 0);
        
        else  dp[i][j] = max( min(dp[i+1][j] , dp[i][j+1]) - a[i][j] , 0);
    }
    return dp[0][0];
}
signed main()
{
	vector<vector<int>> a = { {  -2 ,  -3 ,   3 },
 		                      {  -5 , -10 ,   -1 },
         		              {  10 ,  30 ,   5 } };
	int n = a.size();
	int m = a[0].size();
	
	cout<< MinPoints(a,n,m) <<endl;
	
	return 0;
}
