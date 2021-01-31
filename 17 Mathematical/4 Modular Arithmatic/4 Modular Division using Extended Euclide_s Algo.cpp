#include<bits/stdc++.h>
using namespace std;

int GCD(int a , int b , int &x , int &y)
{
	if(a < b)  return GCD(b , a , y , x);
	
	if(b == 0)
	{
		x = 1;
		
		y = 0;
		
		return a;
	}
	
	int x1 , y1;
	
	int g = GCD(b , a % b , x1 , y1);
	
	x = y1;
	
	y = x1 + (a / b) * y1;
	
	return g;
}

int Multiplicative_Inverse(int b , int m)
{
	int x , y;
	
	int g = GCD(b , m , x , y); //  if bx + my = 1  .. then x is Multiplicative Inverse
	
	if(g != 1)
	return -1;
	
	return (x % m + m) % m;
}

int Mod_Div(int a , int b , int m)
{
	int inv = Multiplicative_Inverse(b , m);
	
	if(inv == -1)
	return -1;
	
	return (a % m * inv % m) % m;
}

signed main()
{
	int a = 8 , b = 3 , m = 5;
	
	cout << Mod_Div(a , b , m) << endl;
		
	return 0;
}
