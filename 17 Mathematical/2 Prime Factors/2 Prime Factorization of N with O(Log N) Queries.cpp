#include<bits/stdc++.h>
using namespace std;
#define Max 10000000

int spf[Max];

void Fill_SPF()  // Smallest Prime Factor by Seive of Eratosthanes
{
	for(int i = 1 ; i < Max ; i++)
	spf[i] = i;
	
	for(int i = 2 ; i * i < Max ; i++)
	if(spf[i] == i)
	{
		for(int j = i * i ; j < Max ; j += i)
		if(spf[j] == j)
		spf[j] = i;
	}
}

void Prime_Factors(int N)  // O(LogN) in case of all 2 LogN worst case
{
	cout << "Prime Factors of " << N << " : ";
	
	if(N == 1)
	{
		cout << 1 << endl;
		
		return;
	}
	
	while(N != 1)
	{
		cout << spf[N] << " ";
		
		N /= spf[N];
	}
	
	cout << endl;
}

signed main()
{	
	Fill_SPF();
	
	Prime_Factors(42);
	
	Prime_Factors(56);
	
	Prime_Factors(24);
	
	Prime_Factors(12246);
	
	return 0;
}

