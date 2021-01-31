#include<bits/stdc++.h>
using namespace std;
int MinimumWeightCost(vector<int> &a,int n)
{
	int mn=*min_element(a.begin(),a.end());
	
	int sum=accumulate(a.begin(),a.end(),0);
	
	return mn * (sum - mn);
}
signed main()
{
	vector<int> a = {6, 2, 1, 5};
	int n=a.size();
	
	cout<< MinimumWeightCost(a,n) <<endl;
	
	return 0;
}
