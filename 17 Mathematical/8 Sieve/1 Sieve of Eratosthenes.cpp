#include<bits/stdc++.h>
using namespace std;

void Sieve(bool P[] , int N)
{
	memset(P,true,sizeof(P));
	
	for(int i = 2 ; i * i <= N ; i++)
	if(P[i])
	{
		for(int j = i * i ; j <= N ; j += i)
		P[j] = false;
	}
}

void Print_All_Prime(int N)
{
	bool P[N+1];
	
	Sieve(P , N);
	
	for(int i = 2 ; i <= N ; i++)
	if(P[i])
	cout << i << " ";
	cout << endl;
}

signed main()
{
	int N = 10;
	
	Print_All_Prime(N);
	
	return 0;
}
