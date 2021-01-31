#include<bits/stdc++.h>
using namespace std;
int MaxJumpPath(vector<int> &a,int n)
{
	vector<int> dp = a;
	
	for(int i=1;i<n;i++)
	for(int j=0;j<=sqrt(i+1)-1;j++)
	if((i+1) % (j+1) == 0)
	dp[i] = max(dp[i] , dp[j] + a[i]);
	
	for(auto i:dp)
	cout<<i<<" ";
	cout<<endl;
}
signed main()
{
	vector<int> a = {2, 3, 1, 4, 6, 5};
	int n = a.size();
	
	MaxJumpPath(a,n);
    
	return 0;
}
