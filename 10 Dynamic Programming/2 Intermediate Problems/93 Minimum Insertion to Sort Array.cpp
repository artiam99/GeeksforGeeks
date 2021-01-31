#include<bits/stdc++.h>
using namespace std;
int MinInsertion(vector<int> &a,int n)
{
	vector<int> dp(n,INT_MAX);
	
	for(int i = 0 ; i < n ; i++)
	dp[ upper_bound(dp.begin(),dp.end(),a[i]) - dp.begin()] = a[i];  // Longest Non Decreasing Subsequence
	
	return n - ( lower_bound(dp.begin() , dp.end() , INT_MAX) - dp.begin());
}
signed main()
{
	vector<int> a = {16, 20, 7, 20, 10, 11, 18, 1, 12};
	int n = a.size();
	
	cout<< MinInsertion(a,n) <<endl;
	
	return 0;
}
