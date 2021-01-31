#include<bits/stdc++.h>
using namespace std;

void selection(int* a , int n)
{
	for(int i = 0 ; i < n-1 ; i++)
	{
		int im = i;
		
		for(int j = i+1 ; j < n ; j++)
		if(a[j] < a[im])
		im = j;
		
		swap(a[i] , a[im]);
	}
}

int main()
{
	int a[] = {7, 5, 6, 3, 4, 2, 1};
	int n = sizeof(a) / sizeof(int);
	
	selection(a , n);

	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";

	return 0;
}

