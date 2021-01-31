#include<bits/stdc++.h>
using namespace std;
int Add(int a,int b)
{
	while(b)
	{
		int carry = (a & b);
		
		a = (a ^ b);
		
		b = (carry << 1);
	}
	
	return a;
}
signed main()
{
	int a = 6 , b = 13;
	
	cout<< Add(a,b) << endl;
	
	return 0;
}
