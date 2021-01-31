#include <bits/stdc++.h> 
using namespace std;
int main() 
{
	int n = 14;
	
	switch(n % 4)   
	{
		case 0:				// Divisible by 4 means There are Two Zeros at the end of Binary Representation
			cout << n;
			break;
			
		case 1:				// If we XOR one to that We will definitely get 1  .. eg 12 ... 1100 ^ 1101 = 0001
		    cout << 1;
		    break;
		    
		case 2:				// in Next Number second palce will be 1 and first palce 0 and XOR the 0001 will just Set the last bit and we will get n + 1
		    cout << n + 1;
		    break;
		    
		case 3:				// (n+1) ^ (n+1) = 0
		    cout << 0;
		    break;
	}
	
	return 0; 
}
