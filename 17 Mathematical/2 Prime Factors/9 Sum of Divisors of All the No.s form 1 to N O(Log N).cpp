#include <iostream>
using namespace std;

int Sum(int N)
{
	return ((N * (N + 1)) / 2);
}

int divisorSum(int N)
{
	int sum = 0;
	
	int i = 1;
	
	while(1)
	{
		sum += (Sum(N / i) - Sum(N / (i + 1))) * i;  // Numbers from N / (i + 1) to N / i appears i times
		
		if(i == N)
		break;
		
		i = N / (N / (i + 1));
	}
	
	return sum;
}

int main()
{
	int N = 5;
	cout << "The sum of divisors of all numbers from 1 to " << N << " is: " << divisorSum(N) << '\n';

	N = 14;
	
	cout << "The sum of divisors of all numbers from 1 to " << N << " is: " << divisorSum(N) << endl;
	
	return 0;
}

