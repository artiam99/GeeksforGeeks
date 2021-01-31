#include <bits/stdc++.h> 
using namespace std;
int Find_N(int K)
{
	if(((K + 1) & K))  return -1;
	
	if(K == 1)  return 2;
	
	return (K >> 1);
}
int main() 
{
	int K = 15;
	
	cout << Find_N(K) << endl;
	
	return 0; 
}
