#include <bits/stdc++.h> 
using namespace std;
int XNOR(int x,int y)
{
	if(x < y)  swap(x,y);
	
	y ^= x;
	
	x |= (x >> 1);  x |= (x >> 2);  x |= (x >> 4);  x |= (x >> 8);  x |= (x >> 16);
	
	return x & ~y;
}
int main() 
{
	int x = 10 , y = 10;
	
	cout << XNOR(x,y) << endl;
	
	return 0; 
}
