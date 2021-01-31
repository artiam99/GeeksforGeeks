#include<bits/stdc++.h>
using namespace std;
int BuildingBridges(vector<int> &a1,vector<int> &a2,int n)
{
	vector<pair<int,int>> a;
	
	for(int i = 0 ; i < n ; i++)
	a.push_back({a2[i] , a1[i]});
	
	sort(a.begin(),a.end());
	
	vector<int> dp(n,INT_MAX);
	
	for(int i = 0 ; i < n ; i++)
	dp[lower_bound(dp.begin(),dp.end(),a[i].second)-dp.begin()] = a[i].second;
	
	return (lower_bound(dp.begin(),dp.end(),INT_MAX)-dp.begin());
}
signed main()
{
	vector<int> a1 = {8, 1, 4, 3, 5, 2, 6, 7};
	
	vector<int> a2 = {1, 2, 3, 4, 5, 6, 7, 8};
	
	int n = a1.size();
	
	cout<< BuildingBridges(a1,a2,n) <<endl;
	
	return 0;
}
