#include<bits/stdc++.h>
using namespace std;

void Factors(int N)  // count to Divisor is D(N) = (e1 + 1) * (e2 + 1) * .. * (en + 1)  ... where N = p1 ^ e1 * p2 ^ e2 * ... * Pn ^ en
{
	int i;
	
	for(i = 1 ; i * i <= N ; i++)
	if(N % i == 0)
	cout << i << " ";
		
	i--;
	
	if(i * i == N)
	i--;
	
	for(; i >= 1 ; i--)
	if(N % i == 0)
	cout << N / i << " ";
	
	cout << endl;
}

signed main()
{
	int N = 100;
	
	Factors(N);
}

