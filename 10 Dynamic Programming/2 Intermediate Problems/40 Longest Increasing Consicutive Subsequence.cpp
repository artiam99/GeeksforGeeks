#include<bits/stdc++.h>
using namespace std;
void LCIS(vector<int> a,int n)
{
	vector<int> dp(n,1) , in(n,-1);
	
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
	if(a[j] < a[i] && (a[i] - a[j]) == 1 && dp[i] < dp[j] + 1)
	{
		dp[i] = dp[j] + 1;
		in[i] = j;
	}
	
	int ind = max_element(dp.begin(),dp.end()) - dp.begin();
	
	vector<int> ans(dp[ind]);
	int i = dp[ind];
	
	while(ind != -1)
	{
		ans[--i] = a[ind];
		
		ind = in[ind];
	}
	
	for(auto i:ans)
	cout<< i <<" ";
	cout<<endl;
}
signed main()
{
	vector<int> a = {6, 7, 8, 3, 4, 5, 9, 10};
	int n = a.size();
	
	LCIS(a,n);
    
	return 0;
}
