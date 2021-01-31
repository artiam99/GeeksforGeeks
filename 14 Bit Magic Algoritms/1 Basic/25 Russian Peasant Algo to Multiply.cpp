#include <bits/stdc++.h> 
using namespace std;
int Multiply(int a,int b)
{
	int res = 0;
	
	while(b)
	{
		if(b & 1)  res += a;
		
		a <<= 1;
		
		b >>= 1;
	}
	
	return res;
}
int main() 
{
	int a = 4 , b = 5;
	
	cout<< Multiply(a,b) << endl;
	
	return 0; 
}
