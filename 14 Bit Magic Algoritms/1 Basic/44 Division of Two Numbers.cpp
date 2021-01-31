#include <bits/stdc++.h> 
using namespace std;
int Divide(int x,int y)
{
	int sign = (((x < 0) ^ (y < 0)) ? -1 : 1) , quotient = 0;;
	
	long long X = abs(x) , Y = abs(y);
		
	for(int i = 30 ; i >= 0 ; i--)
	if(X >= (Y << i))
	{
		X -= (Y << i);
			
		quotient |= (1 << i);
	}
	
	return sign * quotient;
}
int main() 
{
	int x = 100 , y = 7;
	
	cout << Divide(x,y) << endl;
	
	return 0; 
}
