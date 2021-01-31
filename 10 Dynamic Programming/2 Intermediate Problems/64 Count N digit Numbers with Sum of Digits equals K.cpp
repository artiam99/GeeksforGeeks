#include<bits/stdc++.h>
using namespace std;
int CountNumbers(int n,int k) // S(n,k) = { 1 , n==0 , k==0 ; 0 , n==0 || k ==0 ; S(n-1,k-0) + S(n-1,k-1) + .. + S(n-1,k-9)
{
	int dp[n+1][k+1];
    int mod = 1000000007;
    
    for(int i=0;i<=n;i++)
    for(int j=0;j<=k;j++)
    {
        if(i==0 && j==0) dp[i][j] = 1;
        
        else if(j==0 || i==0) dp[i][j]=0;
        
        else
        {
            dp[i][j]=0;
            
			for(int l=0;l<=9;l++)
            dp[i][j] = ( dp[i][j] % mod + ((j >= l) ? dp[i-1][j-l] : 0) % mod) % mod;
        }
    }
    return ((dp[n][k]) ? dp[n][k] : -1);
}
signed main()
{
	int n = 3 , k = 6;
	
	cout<< CountNumbers(n,k) <<endl;
    
	return 0;
}
