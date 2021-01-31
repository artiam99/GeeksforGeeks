#include<bits/stdc++.h>
using namespace std;
int Max_XOR_Subarray(vector<int> &a,int n,int k)
{
	int x = 0 , mx = INT_MIN;
	
	for(int i = 0 ; i < k ; i++)
	x ^= a[i];
	
	for(int i = k ; i <= n ; i++)
	{
		mx = max(mx , x);
		
		if(i == n)  break;
		
		x ^= a[i-k];
		
		x ^= a[i];
	}
	return mx;
}
signed main()
{
	vector<int> a = {8, 1, 2, 7, 12, 6};
	int n = a.size();
	int k = 3;
	
	cout << Max_XOR_Subarray(a,n,k) << endl;
	
	return 0;
}
