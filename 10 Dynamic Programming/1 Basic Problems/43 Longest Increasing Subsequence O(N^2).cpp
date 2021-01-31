#include<bits/stdc++.h>
using namespace std;
int LISS(vector<int> &a,int n)
{
	vector<int> dp(n,1);
	
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
	if(a[j] < a[i])
	dp[i] = max(dp[i] , dp[j] + 1);
	
	return *max_element(dp.begin(),dp.end());
}
signed main()
{
	vector<int> a = {5, 8, 3, 7, 9, 1};
	int n=a.size();
    
    cout<< LISS(a,n) <<endl;
    
	return 0;
}
