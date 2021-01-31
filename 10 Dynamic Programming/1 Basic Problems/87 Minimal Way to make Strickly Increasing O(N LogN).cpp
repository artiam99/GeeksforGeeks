#include<bits/stdc++.h>
using namespace std;
int MinimumChanges(vector<int> &a,int n)
{
	vector<int> dp(n,INT_MAX);
	
	for(int i=0;i<n;i++)
	dp[ upper_bound(dp.begin() , dp.end() , a[i] - i) - dp.begin()] = a[i] - i;
	
	return n - ( lower_bound(dp.begin() , dp.end() , INT_MAX) - dp.begin() );
}
signed main()
{
	vector<int> a = { 1, 2, 6, 5, 4 };
	int n = a.size();
	
	cout<< MinimumChanges(a,n) <<endl;
	
	return 0;
}
