#include<bits/stdc++.h>
using namespace std;
int Min_Sum(vector<int> &a,vector<int> &b,int n,int k)
{
	int ind , mx = INT_MIN;
	
	for(int i = 0 ; i < n ; i++)
	if(mx < abs(b[i]))
	{
		mx = abs(b[i]);
		
		ind = i;
	}
	
	int sum = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(i == ind)
		sum += b[i] * (a[i] + ((b[i] >= 0) ? -2*k : 2*k));
		
		else
		sum += b[i] * a[i];
	}
	
	return sum;
}
signed main()
{
	vector<int> a = {2, 3, 4, 5, 4};
	vector<int> b = {3, 4, 2, 3, 2};
	int n = a.size();
	int k = 3;
	
	cout<< Min_Sum(a,b,n,k) << endl;
	
	return 0;
}
