#include<bits/stdc++.h>
using namespace std;
void SubarrayLengths(vector<int> &a,int n)
{
	int dp[n];
	
	dp[n-1]=1;
	
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]*a[i+1] < 0)
		dp[i] = dp[i+1] + 1;
		
		else
		dp[i] = 1;
		
		cout<< dp[i] <<" ";
	}
	cout<<endl;
}
signed main()
{
	vector<int> a = {-5, -1, -1, 2, -2, -3};
	int n = a.size();
	
	SubarrayLengths(a,n);
	
	return 0;
}
