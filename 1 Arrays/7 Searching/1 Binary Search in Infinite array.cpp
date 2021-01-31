#include<bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int> &a , int l , int r , int x)
{
	while(l <= r)
	{
		int m = l + (r - l) / 2;
		
		if(a[m] == x)
		return m;
		
		else if(a[m] > x)
		r = m - 1;
		
		else
		l = m + 1;
	}
	
	return -1;
}

signed main()
{
	vector<int> a = {-10 , -4, -2, -1, 0, 2, 4, 5, 7, 8, 9};
	int n = a.size();
	int x = 7;
	int l = 0;
	int r = 1;
	
	while(a[r]<x)
	{
		l = r + 1;
		
		r = 2 * r;
		
		if(r > n-1)
		break;
	}
	
	if(r > n)
	r = n-1;
	
	cout << Binary_Search(a , l , r , x) << endl;
	
	return 0;
}
