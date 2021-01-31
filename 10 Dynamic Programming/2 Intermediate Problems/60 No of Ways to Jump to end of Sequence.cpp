#include<bits/stdc++.h>
using namespace std;
void Jump(vector<int> &a,int n)
{
	int dp[n];
	memset(dp,0,sizeof(dp));
	dp[n-1]=1;
	
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]==0)  dp[i]= 0;
		
		else
		{	
			for(int j = i + 1 ; j <= min(i + a[i] , n-1) ; j++)
			dp[i] += dp[j];
		}
	}
	
	for(int i = 0 ; i < n - 1 ; i++)
	cout<< ( (dp[i]) ? dp[i] : -1 ) << " ";
	cout<<0;
	cout<<endl;
}
signed main()
{
	vector<int> a = {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};
	int n = a.size();
	
	Jump(a,n);
    
	return 0;
}
