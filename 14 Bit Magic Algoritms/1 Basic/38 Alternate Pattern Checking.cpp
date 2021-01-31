#include <bits/stdc++.h> 
using namespace std;
bool Check(int n)
{
	n = (n | (n >> 1));  // All Bits Set
	
	return (((n + 1) & n) == 0 );  // Check if All Bits Set
}
int main() 
{
	int n = 10;
	
	if(Check(n))  cout << "YES" << endl;
	
	else  cout << "NO" << endl;
	
	return 0; 
}
