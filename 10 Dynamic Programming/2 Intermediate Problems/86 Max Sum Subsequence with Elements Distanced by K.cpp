#include<bits/stdc++.h>
using namespace std;
int MaxSumSubSeq(vector<int> &a,int n,int k)
{
	int dp[n];  // Max Sum Subseq front i to n-1
	
	dp[n-1] = a[n-1];
	
	for(int i = n-2 ; i >= 0 ; i--)
	{
		if(i + k + 1 >= n)
		dp[i] = max( a[i], dp[i+1] );  // choose a[i] or next max subsequence
		
		else
		dp[i] = max( a[i] , max( a[i] + dp[i+k+1] , dp[i+1] ));  // choose a[i] as single if dp[i+k+1] is negative else take both of next max subsequence
	}
	return dp[0];
}
signed main()
{
	vector<int> a = {4, 5, 8, 7, 5, 4, 3, 4, 6, 5};
	int n = a.size();
	
	int k = 2;
	
	cout<< MaxSumSubSeq(a,n,k) <<endl;
	
	return 0;
}
