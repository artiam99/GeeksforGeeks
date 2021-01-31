#include<bits/stdc++.h>
using namespace std;
int MaxSum(vector<int> &a,int n)
{
	for(int i=2;i<n;i++)
	a[i] = max(a[i-1] , a[i-2] + a[i]);
	
	return a[n-1];
}
signed main()
{
	vector<int> a = {5, 5, 10, 100, 10, 5};
	int n = a.size();
	
	cout<< MaxSum(a,n) <<endl;
    
	return 0;
}
