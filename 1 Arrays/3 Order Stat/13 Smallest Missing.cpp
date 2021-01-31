#include<bits/stdc++.h>
using namespace std;

int smallest_missing(vector<int> &a , int n)
{
	sort(a.begin() , a.end());
	
	int l = 0 , r = n - 1;
	
	while(l <= r)
	{
		if(l != a[l])  return l;
		
		int m = l + (r - l) / 2;
		
		if(a[m] == m)  l = m + 1;
		
		else  r = m;
	}
	
	return a[n-1] + 1;
}

signed main()
 {
	vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 10};
	vector<int> b = {0, 1, 2, 3, 4, 5};
	vector<int> c = {0, 1, 2, 4, 5, 6, 7, 10};
	vector<int> d = {3, 4, 5, 10};
	
	cout << smallest_missing(a , a.size()) << endl;
	cout << smallest_missing(b , b.size()) << endl;
	cout << smallest_missing(c , c.size()) << endl;
	cout << smallest_missing(d , d.size()) << endl;
	
	return 0;
}
