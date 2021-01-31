#include<bits/stdc++.h>
using namespace std;
int Min_Sum(vector<int> &a,vector<int> &b,int n)
{
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	int sum = 0;
	
	for(int i = 0 ; i < n ; i++)
	sum += a[i] * b[n-i-1];
	
	return sum;
}
signed main()
{
	vector<int> a = {4, 5, 6};
	vector<int> b = {-3, 5, -7};
	int n = a.size();
	
	cout<< Min_Sum(a,b,n) << endl;
	
	return 0;
}
