#include<bits/stdc++.h>
using namespace std;
/*
	Phi(N) = No of Co-prime (GCD(A , B) = 1) Numbers of N from 1 to N
	
	For Prime Number P , Phi(P) = P - 1 , As 1 to P-1 ar Co_Prime
	                     
						 Phi(P ^ x) = P ^ x - (P ^ x / P)  as (P ^ x / P) Multiples of P are there from 1 to P ^ x ... Res of the numbers are Co_Prime
						 
						 Phi(N) is Multiplicative function (F(N * M) = F(N) * F(M))  ... Proof is Mathematical by Concept of Rings ... You don't need to know that
						 
						 N = P1 ^ x1 * P2 ^ x2 * .. * Pn ^ xn
						 
						 Phi(N) = Phi(P1 ^ x1) * Phi(P2 ^ x2) * .. * Phi(Pn ^ xn)
						 
				                = (P1 ^ x1 * (P1 - 1) / P1)  * (P2 ^ x2 * (P2 - 1) / P2) * .. * (Pn ^ xn * (Pn - 1) / P1)
				                
				                = N * ((P1 - 1) / P1) * ((P2 - 1) / P2) * .. * ((Pn - 1) / Pn)
*/
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

signed main()
{
	int N = 15;
	
	cout << Phi(N) << endl;
		
	return 0;
}
