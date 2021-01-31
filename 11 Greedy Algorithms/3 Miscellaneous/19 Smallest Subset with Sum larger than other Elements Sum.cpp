#include<bits/stdc++.h>
using namespace std;
int SmallestSubsetSize(vector<int> &a,int n)
{	
	sort(a.begin(),a.end());
	
	for(int i = 1 ; i < n ; i++)
	a[i] += a[i-1];
	
	for(int i = n-2 ; i >= 0 ; i--)
	if(a[n-1] - a[i] > a[i])
	return n-i-1;
	
	return n;
}
signed main()
{
	vector<int> a = {2, 1 , 1};
	int n = a.size();
	
	cout<< SmallestSubsetSize(a,n) << endl;
	
    return 0;
}
