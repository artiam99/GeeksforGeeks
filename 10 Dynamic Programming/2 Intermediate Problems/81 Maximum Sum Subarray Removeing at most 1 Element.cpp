#include<bits/stdc++.h>
using namespace std;
int MaxSumSubarr(vector<int> &a,int n)
{
	if(n==1)  return a[0];
	
	int dp1[n] , dp2[n];
	
	dp1[0] = a[0];
	
	for(int i=1;i<n;i++)
	dp1[i] = max(dp1[i-1] + a[i] , a[i]);
	
	dp2[n-1] = a[n-1];
	
	for(int i=n-2;i>=0;i--)
	dp2[i] = max(dp2[i+1] + a[i] , a[i]);
	
	int mx = INT_MIN , x, y;
	
	for(int i=0;i<n;i++)
	{
		x = ((i==0) ? 0 : dp1[i-1]);
		
		y = ((i==n-1) ? 0 : dp2[i+1]);
		
		mx = max(mx , max(x + y , dp1[i] + dp2[i] - a[i]));
	}
	return mx;
}
signed main()
{
	vector<int> a = {1, -2, 0, 3};
	int n = a.size();
	
	cout<< MaxSumSubarr(a,n) <<endl;
    
	return 0;
}
