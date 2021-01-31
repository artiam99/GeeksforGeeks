#include<bits/stdc++.h>
using namespace std;
int MaxProdIncSubSec(vector<int> &a,int n)
{
	vector<int> dp = a;
	
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
    if(a[i] > a[j])
    dp[i] = max(dp[i], a[i] * dp[j]);
    
    return *max_element(dp.begin(),dp.end());
}
signed main()
{
	vector<int> a = {3, 100, 4, 5, 150, 6};
	int n=a.size();
	
	cout<< MaxProdIncSubSec(a,n) <<endl;
    
	return 0;
}
