#include<bits/stdc++.h>
using namespace std;
void PrintSum(vector<int> a,int n,int sum,vector<vector<bool>> &dp,vector<int> &p)
{	
	if(sum == 0)
	{
		for(auto i:p)
		cout<< i << " ";
		cout<<endl;
		
		return;
	}

	if(n < 0 && sum < 0)
	return;
	
	if(dp[n+1][sum])
	PrintSum(a,n-1,sum,dp,p);
	
	
	if(sum >= a[n] && dp[n+1][sum-a[n]])
	{
		p.push_back(a[n]);

		PrintSum(a,n-1,sum-a[n],dp,p);
		
		p.pop_back();
	}
}
void SubsetSum(vector<int> &a,int n,int V)
{
	vector<vector<bool>> dp(n+1,vector<bool>(V+1));
	dp[0][0]=true;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=V;j++)
		dp[i][j] = ( dp[i-1][j] || ( (j>=a[i-1]) ? dp[i-1][j-a[i-1]] : 0 ) );
	}
	
	if(!dp[n][V])
	{
		cout<< "No Sum found" <<endl;
		return;
	}
	
	vector<int> p;
	
	PrintSum(a,n-1,V,dp,p); 
}
signed main()
{
	vector<int> a={1, 2, 3, 4, 5};
	int n=a.size();
	
	int V=10;
	
	SubsetSum(a,n,V);
	    
	return 0;
}
