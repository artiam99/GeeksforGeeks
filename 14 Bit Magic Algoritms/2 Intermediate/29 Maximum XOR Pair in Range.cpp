#include<bits/stdc++.h> 
using namespace std;
int Max_XOR_Pair(int a,int b)
{
	a = a ^ b;
	
	a |= (a >> 1);  a |= (a >> 2);  a |= (a >> 4);  a |= (a >> 8);  a |= (a >> 16);
	
	return a;
}
int main() 
{
	int a = 8 , b = 20;
	
	cout << Max_XOR_Pair(a,b) << endl;
	
	return 0;
}

