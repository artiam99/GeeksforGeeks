#include<bits/stdc++.h>
using namespace std;

int Sum_of_Largest_Prime_Factors(int N)
{
	int P[100];
	
	for(int i = 0 ; i < 100 ; i++)
	P[i] = 1;
	
	for(int i = 2 ; i * i < 100 ; i++)
	if(P[i] == 1)
	{	
		for(int j = i ; j < 100 ; j += i)
		P[j] = i;
	}

	int sum = 0;
	
	for(int i = 2 ; i <= N ; i++)
	sum += P[i];
	
	return sum;
}

signed main()
{	
	int N = 10;
	
	cout << Sum_of_Largest_Prime_Factors(N) << endl;
}

