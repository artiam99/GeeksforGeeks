#include<bits/stdc++.h>
using namespace std;
int LOEIS(vector<int> a,int n)
{
	vector<int> dp(n,1);
	
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
	if(a[j] < a[i] && (a[i] + a[j])%2 != 0 )
	dp[i] = max(dp[i] , dp[j] + 1);
	
	return *max_element(dp.begin(),dp.end());
}
signed main()
{
	vector<int> a = {1, 12, 2, 22, 5, 30, 31, 14, 17, 11};
	int n = a.size();
	
	cout<< LOEIS(a,n) <<endl;
    
	return 0;
}
