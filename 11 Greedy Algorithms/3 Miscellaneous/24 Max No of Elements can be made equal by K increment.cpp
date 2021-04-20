#include<bits/stdc++.h>
using namespace std;
int upperbound(vector<int> &a,int l,int r,int A,int x)
{
	int ans = r+1;
	
	while(l <= r)
	{
		int m = l + (r-l)/2;
		
		if(A * (m+1) - a[m] > x)
		{
			ans = m;
			
			r = m-1;
		}
		else
		l = m+1;
	}
	return ans;
}
int Max_No_of_Elements(vector<int> &a,int n,int k)
{
	int mx = 1;
	
	for(int i = 1 ; i < n ; i++)
	{
		int ind = upperbound(a, 0 , i-1, a[i] , i * a[i] - a[i-1] - k);
		
		mx = max(mx , i - ind + 1);
		
		a[i] += a[i-1];
	}
	
	return mx;
}
signed main()
{
	vector<int> a = {1, 1, 1, 1, 1, 2, 2};
	int n = a.size();
	int k = 5;
	
	cout<< Max_No_of_Elements(a,n,k) << endl;
	
    return 0;
}
