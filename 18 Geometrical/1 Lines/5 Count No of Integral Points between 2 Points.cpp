#include<bits/stdc++.h>
using namespace std;

/*
	First Making (x2 , y2) origin so (x1 , y1) becomse (x1 - x2 , y1 - y2)
	
	So Equation of the Staight Line is :
	
	y = mx
	
	m = y / x
	
	m = y1 * g / x1 * g ... g is the GCD of y and x
	
	So g could be (excluding origin) .. 1 , 2 , ... , GCD(x1 - x2 , y1 - y2)
	
	And We are not counting (x1 - x2 , y1 - y2) .. So minus 1
*/
int Integral_Points(int x1 , int y1 , int x2 , int y2)
{
	if(x1 == x2 && y1 == y2)
    return 0;
  
    return __gcd(abs(x1 - x2) , abs(y1 - y2)) - 1; 
}

int main()
{
	int x1 = 2 , y1 = 4 , x2 = 10 , y2 = 12;
	
	cout << Integral_Points(x1 , y1 , x2 , y2) << endl;
	
	return 0;
}

