#include<bits/stdc++.h>
using namespace std;

int P[10000];

void Seive()  // phi(N) = N * ((P1 - 1) / P1) * ((P2 - 1) / P2) * .. * ((Pn - 1) / Pn)
{
	for(int i = 0 ; i < 10000 ; i++)
	P[i] = i;
	
	for(int i = 2 ; i < 10000 ; i++)
	if(P[i] == i)
	{
		for(int j = i ; j < 10000 ; j += i)
		{
			P[j] /= i;
			
			P[j] *= (i - 1);
		}
	}
}

int Phi(int N)
{
	return P[N];
}

signed main()
{
	Seive();
	
	int N = 15;
	
	cout << Phi(N) << endl;
		
	return 0;
}
