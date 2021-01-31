#include <bits/stdc++.h> 
using namespace std;
int Max_XOR_Set(int n,int k)
{
	int len = 0;
	
	while(n)
	{
		n >>= 1;
		len++;
	}
	
	return (1 << len) - 1;
}
int main() 
{
	int n = 7 , k = 3;
	
	cout<< Max_XOR_Set(n,k) << endl;
	
	return 0; 
}
