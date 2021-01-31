#include <bits/stdc++.h> 
using namespace std;
int MSB(int n)  // Bit Shift MSB
{
	n |= (n >> 1);  // 100010001
	n |= (n >> 2);  // 110011001
	n |= (n >> 4);  // 111111111
	n |= (n >> 8);  // 111111111
	n |= (n >> 16); // 111111111
	
	n++;  // 1000000000
	
	return (n >> 1);  // 100000000
}
int main() 
{
	int n = 273;
	
	cout << MSB(n) << endl;
	
	return 0; 
}
