#include <iostream>
using namespace std; 
int main() 
{
	int a[] = {2, 3, 7, 9, 11, 2, 3, 11};
	int n = sizeof(a)/sizeof(int);
	
	int res = 0;

	for(int i = 0 ; i < n ; i++)
	res ^= a[i];
	
	int firstsetbit = res & -res;
	
	int x = 0 , y = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(firstsetbit & a[i])  x ^= a[i];
		
		else  y ^= a[i];
	}
	
	(x < y) ? cout<< x << " " << y << endl : cout << y << " " << x << endl;
	
	return 0; 
} 

