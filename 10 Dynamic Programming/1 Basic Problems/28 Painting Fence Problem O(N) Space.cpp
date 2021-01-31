#include<bits/stdc++.h>
using namespace std;
int Paint(int n,int k)
{
	vector<int> dp(n+1);
	
	dp[1]=k;
	dp[2]=k*k;
	
	for(int i=3;i<=n;i++)
	dp[i] = (k-1)*(dp[i-1] + dp[i-2]);  //  Same means if same color in ith and (i-1)th fence that is possible if (i-1)th and (i-2)th are different so same(i) = diff(i-1) 
                                       //   diff color in ith fence means if i-1 and i-2 are diff or same it doesn't matter so diff(i) = (same(i-1) + diff(i-1) ) * (k-1)
	return dp[n];
}
signed main()
{
	int n=3,k=2;
	
	cout<< Paint(n,k);
	    
	return 0;
}
