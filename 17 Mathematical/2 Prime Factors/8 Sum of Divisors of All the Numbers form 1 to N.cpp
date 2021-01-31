#include<bits/stdc++.h>
using namespace std;

int Sum_of_Divisors(int N)
{
	int sum = 0;
	
	for(int i = 1 ; i <= N ; i++) // 1 appers in every numbers , 2 in even , 3 in multiple of 3s , and so on
	sum += (N / i) * i;
	
	return sum;
}

signed main()
{	
	int N = 4;
	
	cout << Sum_of_Divisors(N) << endl;
}

