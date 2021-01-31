#include<bits/stdc++.h>
using namespace std;
void Swap(int &a,int &b)
{
	a = a ^ b;
	
	b = a ^ b;
	
	a = a ^ b;
}
signed main()
{
	int a = 7 , b = 6;
	
	Swap(a,b);
	
	cout<< a << " " << b << endl;
	
	return 0;
}
