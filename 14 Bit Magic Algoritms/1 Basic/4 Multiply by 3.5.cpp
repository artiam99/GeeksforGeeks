#include<bits/stdc++.h>
using namespace std;
int Multiply(int a)
{
	return (a << 1) + a + (a >> 1); //  2 * a + a + a / 2 = a * 3.5
}
signed main()
{
	int a = 6 ;
	
	cout<< Multiply(a) << endl;
	
	return 0;
}
