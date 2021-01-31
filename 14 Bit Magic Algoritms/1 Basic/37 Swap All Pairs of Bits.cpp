#include <bits/stdc++.h> 
using namespace std;
int Swap_Pair_Bits(int n)
{
	return ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);  //  Odd Going to Even ... Even Going to Odd
}
int main() 
{
	int n = 4;
	
	cout<< Swap_Pair_Bits(n) << endl;
	
	return 0; 
}
