#include<bits/stdc++.h>
using namespace std;

long long Modular_Multiplication(long long a , long long b , long long m)  // Russian Pheasant
{
	long long ans = 0;
	
	while(b > 0)
	{
		if((b & 1LL))
		ans = (ans % m + a % m) % m;
		
		a = (a % m * 2 % m) % m;
		
		b /= 2;
	}
	
	return ans % m;
}

signed main()
{
	long long a = 9223372036854775807, b = 9223372036854775807 , m = 100000000000;
	
	cout << Modular_Multiplication(a , b , m) << endl;
		
	return 0;
}
