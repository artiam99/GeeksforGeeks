#include<bits/stdc++.h>
using namespace std;
bool isPresent(vector<int> &a,int n,int m)
{
	vector<bool> dp(m);
	
	for(int i=0;i<n;i++)
	{
		if(dp[0])
		return true;
		
		vector<bool> temp(m);
		
		for(int j=0;j<m;j++)
		if(dp[j])
		temp[(j + a[i]) % m]=true;
		
		for(int j=0;j<m;j++)
		if(temp[j])
		dp[j]=true;
		
		dp[a[i] % m]=true;
	}
	return dp[0];
}
signed main()
{
	vector<int> a={3, 1, 7, 5};
	int n=a.size();
	
	int m=6;
	
	if(isPresent(a,n,m))
	cout<< "Present" <<endl;
	else
	cout<< "Not Present" <<endl;
	    
	return 0;
}
