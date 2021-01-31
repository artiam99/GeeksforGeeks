#include<bits/stdc++.h>
using namespace std;

void Multiplicative_Inverse(int n , int m)
{
	int inv[n+1];
	
	inv[0] = inv[1] = 1;
	
	for(int i = 2 ; i <= n ; i++)
	{
		inv[i] = (m - (m / i) * inv[m % i] % m) % m;
		
		cout << inv[i] << endl;
	}
}

signed main()
{
	int n = 10 , m = 553123;
	
	Multiplicative_Inverse(n , m);
		
	return 0;
}
