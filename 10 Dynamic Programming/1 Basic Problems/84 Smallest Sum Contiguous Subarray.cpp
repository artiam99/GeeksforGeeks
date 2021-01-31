#include<bits/stdc++.h>
using namespace std;
int SSCS(vector<int> &a,int n)
{
	int curr = a[0];
	int sofar = a[0];
	
	for(int i=1;i<n;i++)
	{
		curr = min(curr + a[i] , a[i]);
		
		sofar = min(sofar,curr);
	}
	
	return sofar;
}
signed main()
{
	vector<int> a = {3, -4, 2, -3, -1, 7, -5};
	int n = a.size();
	
	cout<< SSCS(a,n) <<endl;
	
	return 0;
}
