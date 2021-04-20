#include<bits/stdc++.h>
using namespace std;

int Minimum_Sum_Factors(int N)
{
	int sum = 0 , M = N;
	
	for(int i = 2 ; i * i <= N ; i++)
	{
		while(N % i == 0)
		{
			sum += i;
			
			N /= i;
		}
	}
	
	if(N >= 2)
	sum += N;
	
	if(sum == M)  // Minimum Sum of Factors is equal to sum of prime factors except prime numbers eg . 11 => 11 + 1 = 12
	sum++;
	
	return sum;
}

signed main()
{
	int N = 4;
	
	cout << Minimum_Sum_Factors(N) << endl;
}
