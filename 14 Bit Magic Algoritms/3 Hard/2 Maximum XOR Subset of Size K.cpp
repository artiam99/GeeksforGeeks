#include<bits/stdc++.h>
using namespace std;
int dp[50][50][10000];
int Rec(vector<int> &a,int n,int k,int mask)
{
	if(k == 0)  return mask;
	
	if(n < 0)  return 0;
	
	if(dp[n][k][mask] != -1)  return dp[n][k][mask];
	
	return dp[n][k][mask] = max(Rec(a,n-1,k,mask) , Rec(a,n-1,k-1,mask ^ a[n]));
}
int Max_XOR_Subset(vector<int> &a,int n,int k)
{
	memset(dp,-1,sizeof(dp));
	
	return Rec(a,n-1,k,0);
}
signed main()
{
	vector<int> a = {2, 5, 4, 1, 3, 7, 6, 8};
	int n = a.size();
	int k = 3;
	
	cout << Max_XOR_Subset(a,n,k) << endl;
	
	return 0;
}
