#include <bits/stdc++.h> 
using namespace std; 

void shufleArray(int a[] , int f , int l)
{
	if (f > l)
	return;
		
	if (l - f == 1) 
	return;
		
	int mid = (f + l) / 2;

	int temp = mid + 1;
	
	int mmid = (f + mid) / 2;
	
	for (int i = mmid + 1; i <= mid; i++) 
	swap(a[i] , a[temp++]); 

	shufleArray(a , f , mid);
	
	shufleArray(a , mid + 1 , l);
}

int main()
{
	int a[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	shufleArray(a, 0, n - 1);

	for (int i = 0 ; i < n ; i++)
	cout << a[i] << " ";

	return 0;
}

