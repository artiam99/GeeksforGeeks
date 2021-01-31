#include <bits/stdc++.h> 
using namespace std;
int xorsubset(int *a,int n)
{
	if(n==1)
	return a[0];
	else
	return 0;
}
int main() 
{
	int a[]={1,2,3};
	int n=sizeof(a)/sizeof(int);
	cout<<xorsubset(a,n);
	return 0; 
}
