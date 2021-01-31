#include<bits/stdc++.h>
using namespace std;
int check(int n)
{
	return (n && !(n & (n-1)) && !(n & 0xAAAAAAAA));// 0xAAAAAAAA = 10101010101010101010101010101010
}
signed main()
{
	int n = 64;
	
	if(check(n))  cout<< "4's Power" << endl;
	
	else  cout<< "Not 4's Power" << endl;
	
	return 0;
}
