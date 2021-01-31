#include <bits/stdc++.h> 
using namespace std;
int Remainder(int divident , int divisor)
{	
	int quotient = 0 , rem = 0;
	
	long long X = abs(divident) , Y = abs(divisor);  // Must be Long Long otherwise Overflow
		
	for(int i = 30 ; i >= 0 ; i--)
	if(X >= (Y << i))
	{	
		X -= (Y << i);
			
		quotient |= (1 << i);
	}
	return X;
}
int main() 
{
	int divident = 15 , divisor = 8;
	
	cout << Remainder(divident , divisor) << endl;
	
	return 0; 
}
