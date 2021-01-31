#include<bits/stdc++.h>
using namespace std;
int NoofIS(vector<int> &a,int n)
{
	vector<int> dp(n,1);	
	
	for(int i = 1 ; i < n ; i++)
	for(int j = 0 ; j < i ; j++)
	if(a[j] < a[i])
	dp[i] += dp[j];
	
	return accumulate(dp.begin(),dp.end(),0);
}
signed main()
{
	vector<int> a = {3, 2, 4, 5, 4};
	int n = a.size();
	
	cout<< NoofIS(a,n) <<endl;
    
	return 0; 
}
