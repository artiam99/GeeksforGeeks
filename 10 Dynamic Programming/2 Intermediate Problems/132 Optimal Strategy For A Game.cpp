#include<bits/stdc++.h>
using namespace std;
int MaxScore(vector<int> &a,int n)
{
	int dp[n][n];
	
	for(int i = n-1 ; i >= 0 ; i--)
	for(int j = i ; j < n ; j++)
	{
		if(i == j)  dp[i][j] = a[i];
		
		else
		dp[i][j] = max( a[i] + min( ((i+2 <= j) ? dp[i+2][j] : 0) , ((i+1 <= j-1) ? dp[i+1][j-1] : 0) ) ,
		                a[j] + min( ((i <= j-2) ? dp[i][j-2] : 0) , ((i+1 <= j-1) ? dp[i+1][j-1] : 0) ));
	}
	return dp[0][n-1];
}
signed main()
{
	vector<int> a = {5, 3, 7, 10};
	int n = a.size();
	
	cout<< MaxScore(a,n) <<endl;
	
	return 0;
}
