#include<bits/stdc++.h>
using namespace std;
int gcd(int a , int b , int &x , int &y)
{
	if(a < b)  return gcd(b , a , y , x);
	
	if(b == 0)
	{
		x = 1;
		
		y = 0;
		
		return a;
	}
	
	int x1 , y1;
	
	int g = gcd(b , a % b , x1 , y1);
	
	x = y1;
	
	y = x1 - (a / b) * y1;  // g = (b * x1 + r * y1)   =   (b * x1 + (a - b * q) * y1)   =   (a * y1 + b * (x1 - q * y1))
	
	return g;
}

int main()
{
	int a = 10 , b = 7 , x , y;
	
	int g = gcd(a , b , x , y);
	
	cout << a << " * ( " << x << " ) + " << b << " * ( " << y << " ) = " << g << endl;
	
	return 0;
}
