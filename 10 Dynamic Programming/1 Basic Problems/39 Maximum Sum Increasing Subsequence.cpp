#include<bits/stdc++.h>
using namespace std;
int MaxSumIncSubSec(vector<int> &a,int n)
{
	vector<int> dp = a;
	
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
    if(a[i] > a[j])
    dp[i] = max(dp[i], a[i] + dp[j]);
    
    return *max_element(dp.begin(),dp.end());
}
signed main()
{
	vector<int> a = {1, 101, 2, 3, 100, 4, 5};
	int n=a.size();
	
	cout<< MaxSumIncSubSec(a,n) <<endl;
    
	return 0;
}
