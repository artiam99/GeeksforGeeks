#include<bits/stdc++.h>
using namespace std;

void bubble(int *a , int n)
{
	for(int i = 0 ; i < n-1 ;i++)
	for(int j = 0 ; j < n-1-i ; j++)
	if(a[j] > a[j+1])
	swap(a[j] , a[j+1]);
}

int main()
{
	int a[]={7, 5, 6, 3, 4, 2, 1};
	int n = sizeof(a) / sizeof(int);
	
	bubble(a , n);

	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";

	return 0;
}

