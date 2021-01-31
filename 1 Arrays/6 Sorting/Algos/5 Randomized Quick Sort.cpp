#include<bits/stdc++.h>
using namespace std;

int partition(int *a , int l , int r)
{
	int pivot = a[r];
	int pi = l;
	
	for(int i = l ; i < r ; i++)
	if(a[i] <= pivot)
	{
		swap(a[i] , a[pi]);
	
		pi++;
	}
	
	swap(a[pi] , a[r]);
	
	return pi;
}

int randpartition(int *a , int l , int r)
{
	int p = rand() % (r - l + 1) + l;

	swap(a[p] , a[r]);

	return partition(a , l , r);
}

void quicksort(int* a , int l , int r)
{
	if(l < r)
	{
	
	    int pi = randpartition(a , l , r);
	    
    	quicksort(a , l , pi - 1);

    	quicksort(a , pi + 1 , r);
    }
}

int main()
{
	srand(time(NULL));

	int a[] = {7, 6, 5, 4, 3, 2, 1};
	int n = sizeof(a) / sizeof(int);
	
	quicksort(a , 0 , 6);

	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";

	return 0;
}

