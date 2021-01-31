#include<bits/stdc++.h>
using namespace std;
/*
	N = 12
	
	GCD(1 , 12)  = 1   GCD(2 , 12)  = 2   GCD(3 , 12)  = 3
	GCD(4 , 12)  = 4   GCD(5 , 12)  = 1   GCD(6 , 12)  = 6
	GCD(7 , 12)  = 1   GCD(8 , 12)  = 4   GCD(9 , 12)  = 3
	GCD(10 , 12) = 2   GCD(11 , 12) = 1   GCD(12 , 12) = 12
	
	ans = 1 * 4 + 2 * 2 + 3 * 2 + 4 * 2 + 6 * 1 + 12 * 1 = 40
	
	1 , 2 , 3 , 4 , 6 and 12 are the divisors So GCD with 12 will give result among these numbers 
	
	1 appears 4 times , 2 apperas 2 times , 3 appears 2 times , 4 appears 2 times , 6 appears once and 12 appears once
	
	So we need to Find How many times these Divisors are appearing as GCD
	
	GCD(x , N) = D
	
	GCD(x/D , N/D) = 1
	
	as 1 <= x <= N  =>  1 <= x/D <= N/D   as  1 <= D <= x
	
	So We just Need to find the Phi(N / D)
*/

void Sieve(int Phi[] , int N)
{
	for(int i = 0 ; i <= N ; i++)
	Phi[i] = i;
	
	for(int i = 2 ; i * i <= N ; i++)
	if(Phi[i] == i)
	{
		for(int j = i ; j <= N ; j += i)
		{
			Phi[j] *= (i - 1);
			
			Phi[j] /= i;
		}
	}
}

int GCD_Pair_Sum(int N)
{
	int Phi[N+1];
	
	Sieve(Phi , N);
	
	int res = 0;
	
	for(int i = 1 ; i * i <= N ; i++)
	if(N % i == 0)
	{	
		res += i * Phi[N / i];
		
		if(i * i != N)
		res += (N / i) * Phi[i];
	}
	
	return res;
}

signed main()
{
	int N = 12;
	
	cout << GCD_Pair_Sum(N) << endl;
		
	return 0;
}
