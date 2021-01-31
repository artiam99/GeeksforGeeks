#include <bits/stdc++.h>
using namespace std;

int leftrotate(int a[] , int n)
{
	int c = 0 , p;
	
	vector<int> r(n);
	
	for(int i = 0 ; i < n ; i++)
	{
		c += a[i];
		
		r[0] += i * a[i];
	}
	
	p = r[0];
	
	for(int i = 1 ; i < n ; i++)
	{
		r[i] = r[i-1] + c - a[n-i] + (1 - n) * a[n-i];
		
		p = max(p , r[i]);
	}
	
	return p;
}

int main()
{
	int a[] = {1, 20, 2, 10};
	int n = sizeof(a)/sizeof(int);
	
	cout << leftrotate(a,n) << endl;
	
	return 0;
}

