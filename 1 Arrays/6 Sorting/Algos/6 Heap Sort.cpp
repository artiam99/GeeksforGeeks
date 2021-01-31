#include <bits/stdc++.h>
using namespace std;

void heapf(int *a , int n , int i)
{
	int largest = i;
	
	int l = 2 * i + 1;
	int r = l + 1;
	
	if(l < n && a[l] > a[largest])
	largest = l;
	
	if(r < n && a[r] > a[largest])
	largest = r;
	
	if(largest != i)
	{
		swap(a[i] , a[largest]);
		
		heapf(a , n , largest);
	}
}

void deletion(int *a , int n)
{
	int m = n-1;
	
	while(m--)
	{
		swap(a[0] , a[n-1]);
	
		n--;
	
		heapf(a , n , 0);
	}
}

void heapify(int *a , int n)
{
	for(int i = n/2-1 ; i >= 0 ; i--)
	heapf(a , n , i);
}

void heapsort(int *a , int n)
{
	heapify(a , n);

	deletion(a , n);
}

void printarray(int *a , int n)
{
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[] = {7, 6, 5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);

	printarray(a , n);
	
	heapsort(a , n);
	
	printarray(a , n);

	return 0;
}

