#include<bits/stdc++.h>
using namespace std;
void PrintPartition(vector<int> &a,int n)
{
	int sum = accumulate(a.begin(),a.end(),0);
	
	if(sum%2!=0)
	{
		cout<<-1<<endl;
		return;
	}
	
	vector<vector<bool>> dp(n+1,vector<bool>(sum/2+1));
	
	for(int i=0;i<=n;i++)
	dp[i][0] = true;

	
	for(int i=1;i<=n;i++)
	for(int j=0;j<=sum/2+1;j++)
	dp[i][j] = dp[i-1][j] | ((j >= a[i-1]) ? dp[i-1][j-a[i-1]] : false );
	
	if(!dp[n][sum/2])
	{
		cout<<-1<<endl;
		return;
	}
	
	int i = n , j = sum/2;
	
	vector<int> set1,set2;
	
	while(i>0 && j>=0)
	{
		if(dp[i-1][j])
		{
			set1.push_back(a[i-1]);
			i--;
		}
		else
		{
			set2.push_back(a[i-1]);
			j -= a[i-1];
			i--;
		}
	}
	
	cout<<"Set1 : ";
	for(auto i:set1)
	cout<<i<<" ";
	
	cout<<endl;
	
	cout<<"Set2 : ";
	for(auto i:set2)
	cout<<i<<" ";
	
	cout<<endl;
}
signed main()
{
	vector<int> a = {1, 5, 11, 5};
	int n = a.size();
	
	PrintPartition(a,n);
    
	return 0;
}
