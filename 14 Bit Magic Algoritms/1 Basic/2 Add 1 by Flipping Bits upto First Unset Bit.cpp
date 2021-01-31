#include<bits/stdc++.h>
using namespace std;
int AddOne(int a)
{
	int m = 1;
	
	while(m & a)
	{
		a = a ^ m;
		
		m <<= 1;
	}
	
	a = a ^ m;
	
	return a;
}
signed main()
{
	int a = 6;
	
	cout<< AddOne(a) << endl;
	
	return 0;
}
