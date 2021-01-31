#include <iostream>
using namespace std; 
int main() 
{
	int a[] = {1, 1, 2, 3, 3, 3, 3};
	int n = sizeof(a)/sizeof(int);
	
	int res=0;
	
	for(int i = 0 ; i < n ; i++)
	res ^= a[i];
	
	cout<< res << endl;
	
	return 0; 
} 

