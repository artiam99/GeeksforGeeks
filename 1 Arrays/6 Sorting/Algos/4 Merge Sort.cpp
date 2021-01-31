#include<bits/stdc++.h>
using namespace std;

void merge(int *a , int l , int r , int m)
{
	int n1 = m - l + 1 , n2 = r - m;
	
	int L[n1] , R[n2];
	
	for(int i = 0 ; i < n1 ; i++)
	L[i] = a[i+l];

	for(int i = 0 ; i < n2 ; i++)
	R[i] = a[m+1+i];
	
	int i = 0 , j = 0 , k = l;
	
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		a[k++] = L[i++];
		
		else
		a[k++] = R[j++];
	}
	
	while(i < n1)
	a[k++] = L[i++];
	
	while(j < n2)
	a[k++] = R[j++];
}

void mergesort(int* a , int l , int r)
{
	if(l < r)
	{
	    int m = l + (r - l) / 2;
	
    	mergesort(a , l , m);

    	mergesort(a , m+1 , r);

    	merge(a , l , r , m);
    }
}

int main()
{
	int a[]={7, 5, 6, 3, 4, 2, 1};
	int n = sizeof(a) / sizeof(int);
	
	mergesort(a , 0 , 6);
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";

	return 0;
}

