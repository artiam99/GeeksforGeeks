#include<bits/stdc++.h> 
using namespace std;
bool isSparse(long long n)
{
	return !(n & (n >> 1));  // No Adjacent Set Bits
}
int main() 
{ 
	long long n = 17;
	
	if(isSparse(n))  cout << "YES" << endl;
	
	else cout << "NO" << endl;
	
	return 0; 
} 

