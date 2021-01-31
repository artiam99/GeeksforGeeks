#include<bits/stdc++.h>
using namespace std;

int Phi(int N)
{
	int res = N;
	
	for(int i = 2 ; i * i <= N ; i++)
	if(N % i == 0)
	{
		while(N % i == 0)
		N /= i;
		
		res *= (i - 1);
		
		res /= i;
	}
	
	if(N > 1)
	res *= (N - 1) , res /= N;
	
	return res;
}

int Pow(int x , int n , int m)
{
	int res = 1;
	
    while (n > 0)
	{
        if (n & 1)
        res = (res % m * x % m) % m; 
    
	    x = (x % m * x % m) % m;
    
	    n >>= 1;
    }
    
	return res;
}

int Multiplicative_Inverse(int a , int m) // Fermat's Theorem if a and m are co-prime then , a ^ Phi(m) = (1 mod m) => (a * a ^ (phi(m) - 1)) % m = 1
{										 //  For Prime m .. (a ^ (m - 1)) % m = 1
    if(m == 1)  return -1;
    
    if(__gcd(a , m) != 1)
    return -1;
    
    int phi = Phi(m);
    
    return Pow(a , phi - 1 , m);
}

signed main()
{
	int a = 3 , m = 11;
	
	cout << Multiplicative_Inverse(a , m) << endl;
		
	return 0;
}
