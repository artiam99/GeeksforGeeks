#include<bits/stdc++.h>
using namespace std;
int MaxSumPair(vector<int> &a,int n,int k)
{
	sort(a.begin(),a.end());
	
	int mx = 0;
	
	for(int i=n-1;i>0;i--)
	if(a[i] - a[i-1] < k)
	mx += a[i--] + a[i];
	
	return mx;
}
signed main()
{
	vector<int> a = {3, 5, 10, 15, 17, 12, 9};
	int n = a.size();
	int k = 4;
	
	cout<< MaxSumPair(a,n,k) <<endl;
    
	return 0;
}
