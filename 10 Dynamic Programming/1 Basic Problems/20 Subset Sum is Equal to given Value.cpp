#include<bits/stdc++.h>
using namespace std;
bool isPresent(vector<int> &a,int n,int V)
{
	bool dp[2][V+1];
	
	for(int i=0;i<V+1;i++)
	dp[0][i]=dp[1][i]=false;
	
	dp[0][0]=true;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=V;j++)
		{
			if(i&1)
			dp[0][j] = (j>=a[i]) ? dp[1][j-a[i]] : dp[1][j];
			
			else
			dp[1][j] = (j>=a[i]) ? dp[0][j-a[i]] : dp[0][j];
		}
		
		if(dp[1-i%2][V])
		return true;
	}
	return false;
}
signed main()
{
	vector<int> a={3, 34, 4, 12, 5, 2};
	int n=a.size();
	
	int V=17;
	
	if(isPresent(a,n,V))
	cout<<"Present"<<endl;
	else
	cout<<"Not Present"<<endl;
    
	return 0;
}
