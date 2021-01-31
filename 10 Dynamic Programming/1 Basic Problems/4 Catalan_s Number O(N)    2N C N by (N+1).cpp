#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int Catalan(int n)
{
	vector<int> dp(101);
	dp[0]=1;
	
	for(int i=1;i<=100;i++)
	{
		for(int j=0;j<i;j++)
		dp[i] = ( dp[i] % mod + ( dp[j] % mod * dp[i-j-1] % mod ) % mod ) % mod;
	}
	
	return dp[n];
}
signed main()// Binary Tree , Balanced Parentheses Pairs , Stack Sortable Permutations of 1,..,n , Non intersecting n chords with 2n points
{
    int n=5;
    
    cout<< Catalan(n) <<endl;
    
	return 0;
}
