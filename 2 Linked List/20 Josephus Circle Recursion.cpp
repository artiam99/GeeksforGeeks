#include<bits/stdc++.h>
using namespace std;

int josephus(int n , int m)
{
	if(n == 1)  return 1;
	
	return (m - 1 + josephus(n-1 , m)) % n + 1;
}

int main() 
{
	int n = 4 , m = 2;
	
	cout << josephus(n,m) << endl;
	
	n = 2 ; m = 1;
	
	cout << josephus(n , m) << endl;;
	
	n = 4 ; m = 2;
	
	cout << josephus(n , m) << endl;
	
	n = 50 ; m = 10;
	
	cout << josephus(n , m) << endl;
	
	return 0;
}
