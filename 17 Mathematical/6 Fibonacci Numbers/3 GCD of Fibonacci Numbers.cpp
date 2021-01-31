#include<bits/stdc++.h>
using namespace std;

int Fibo(int N)
{
	if(N <= 1) return N;
	
	int x = 1 , y = 0;
	
	while(N--)
	{
		int t = x;
		
		x = x + y;
		
		y = t;
	}
	
	return y;
}

int GCD_Fibo(int N , int M)  // GCD(Fibo(N) , Fibo(M)) = Fibo(GCD(N , M))  .... M divides N then F(M) also divides N
{
	int g = __gcd(N , M);
	
	return Fibo(g);
}

signed main()
{
	int N = 8 , M = 12;
	
	cout << GCD_Fibo(N , M) << endl;
	
	return 0;
}
