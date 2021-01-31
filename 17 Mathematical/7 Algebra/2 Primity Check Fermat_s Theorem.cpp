#include <bits/stdc++.h>
using namespace std;

int power(int a , unsigned int n , int p)
{
	int res = 1;

	a = a % p;

	while (n > 0)
	{
		if (n & 1)
		res = (res * a) % p;

		n >>= 1;

		a = (a*a) % p;
	}

	return res;
}

int gcd(int a , int b)
{
	if(a < b)
	return gcd(b , a);
	
	else if(a % b == 0)
	return b;

	return gcd(b , a % b);
}

bool isPrime(unsigned int n , int k)
{
	if(n <= 1 || n == 4) return false;
	
	if(n <= 3) return true;

	while (k > 0)
	{
		int a = 2 + rand() % (n - 4); 

		if (gcd(n, a) != 1)
		return false;

		if (power(a, n-1, n) != 1)
		return false;

		k--;
	}

	return true;
}

int main()
{
	int k = 3;
	
	isPrime(11, k)? cout << " true\n": cout << " false\n";
	
	isPrime(15, k)? cout << " true\n": cout << " false\n";
	
	return 0;
}

