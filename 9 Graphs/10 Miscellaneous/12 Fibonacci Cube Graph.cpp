#include<bits/stdc++.h>
using namespace std;
#define int long long
int Fibo(int n)
{
	if(n<=1)
	return n;
	return Fibo(n-1) + Fibo(n-2);
}
signed main()
{
	int n=5;
	
	cout<< "Number of vertices in Fibonacci Cube Graph of Degree "<< n <<" is "<< Fibo(n+2) <<endl;
	
	return 0;
}
