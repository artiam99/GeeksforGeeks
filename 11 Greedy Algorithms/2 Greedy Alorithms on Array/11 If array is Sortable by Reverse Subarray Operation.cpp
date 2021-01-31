#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &a,int n)
{
	int l , r , mn , mx;
	
	if(n & 1)  l = (n/2) - 1 , r = (n/2) + 1 , mn = a[n/2] , mx = a[n/2];
	
	else  l = (n/2) - 1 , r = (n/2) , mn = min(a[l],a[r]) , mx = max(a[l],a[r]);
	
	while(l >= 0 && r < n)
	{
		if((a[l] > mn && a[r] > mn) ||
		   (a[l] < mx && a[r] < mx) ||
		   (a[l] < mn && a[r] < mn) ||
		   (a[l] > mx && a[r] > mx))
		return false;
		
		mn = min(mn , min(a[l] , a[r]));
		mx = max(mx , max(a[l] , a[r]));
		
		l--;  r++;
	}
	return true;
}
signed main()
{
	vector<int> a = {1, 6, 3, 4, 5, 2, 7};
	int n = a.size();
	
	if(check(a,n))  cout<< "Yes" <<endl;
	
	else  cout<< "No" <<endl;
	
	vector<int> b = {1, 6, 3, 4, 5, 7, 2};
	int m = b.size();
	
	if(check(b,m))  cout<< "Yes" <<endl;
	
	else  cout<< "No" <<endl;
	
	return 0;
}
