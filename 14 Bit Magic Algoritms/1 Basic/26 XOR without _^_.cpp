#include <bits/stdc++.h> 
using namespace std;
int XOR(int a,int b)
{
	return ((a | b) & (~a | ~b));  //  ((a & ~b) | (~a & b))
}
int main() 
{
	int a = 4 , b = 5;
	
	cout<< XOR(a,b) << endl;
	
	return 0; 
}
