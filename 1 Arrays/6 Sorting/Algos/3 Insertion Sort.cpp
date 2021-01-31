#include<bits/stdc++.h>
using namespace std;

void insertion(int *a , int n)
{
	for(int i = 1 ; i < n ; i++)
	{
		int hole = i;
		
		int v = a[hole];
		
		while(a[hole-1] > v && hole > 0)
		{
			a[hole] = a[hole-1];
			
			hole--;
		}
		
		a[hole] = v;
	}
}

int main()
{
	int a[]={7, 5, 6, 3, 4, 2, 1};
	int n = sizeof(a) / sizeof(int);
	
    insertion(a , n);

	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";

	return 0;
}

