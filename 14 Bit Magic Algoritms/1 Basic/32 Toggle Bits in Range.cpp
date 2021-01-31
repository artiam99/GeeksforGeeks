#include <bits/stdc++.h> 
using namespace std;
int Toggle(int n,int l,int r)
{
	int x = (((1 << (r - l + 1)) - 1) << (l-1));
	
	return (n ^ x);
}
int main() 
{
	int n = 50 , l = 2 , r = 5;
	
	cout<< Toggle(n,l,r) << endl;
	
	return 0; 
}
