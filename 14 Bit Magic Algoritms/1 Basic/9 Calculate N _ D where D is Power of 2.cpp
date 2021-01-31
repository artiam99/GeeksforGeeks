#include<bits/stdc++.h>
using namespace std;
int Modulus(int n,int d)
{
	return n & ~d;
}
signed main()
{
	int n = 14 , d = 8;
	
	cout<< Modulus(n,d) << endl;
	
	return 0;
}
