#include <bits/stdc++.h> 
using namespace std;
int SmallestNumber(int n,int m)
{
	int x = (1 << (n + m - 1)) | ((1 << (n-1)) - 1);
	
	return x;
}
int main() 
{
	int n = 2 , m = 2;
	
	cout<< SmallestNumber(n,m) << endl;
	
	return 0; 
}
