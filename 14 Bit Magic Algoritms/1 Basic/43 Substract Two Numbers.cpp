#include <bits/stdc++.h> 
using namespace std;
int Substract(int x,int y)
{
	while(y)
	{
		int borrow = ~x & y;
		
		x = x ^ y;
		
		y = (borrow << 1);
	}
	return x;
}
int main() 
{
	int x = 3 , y = 4;
	
	cout << Substract(x,y) << endl;
	
	return 0; 
}
