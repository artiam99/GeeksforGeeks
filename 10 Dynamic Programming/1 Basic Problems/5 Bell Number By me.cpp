#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int Bell(int n)
{
	//Bell(N) = (N-1) C 0 * Bell(0) + (N-1) C 1 * Bell(1) + ... + (N-1) C (N-1) * Bell(N-1)
	
	vector<vector<int>> pascal;// Pascal's Triangle to get 
    for(int i=0;i<=n;i++)     // N C R in O(1) time , 0<=N<=n , 0<=R<=N
    {
        pascal.push_back(vector<int>(i+1,1));
        
		for(int j=1;j<i;j++)
        pascal[i][j]=(pascal[i-1][j]%mod + pascal[i-1][j-1]%mod)%mod;
    }
    
    int dp[n+1];
    memset(dp,0,sizeof(dp));  dp[0]=1;
    
    for(int i=1;i<=n;i++)
    for(int j=0;j<i;j++)
    dp[i]= (dp[i]%mod + (pascal[i-1][j]%mod * dp[j]%mod)%mod ) %mod;
    
    return dp[n];
}
signed main()
{
    int n=3;
    
    cout<< Bell(n) <<endl;
    
	return 0;
}
