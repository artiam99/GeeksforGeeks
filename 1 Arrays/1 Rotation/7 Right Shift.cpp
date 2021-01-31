#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b)
{
	if(b == 0)  return a;
	
	return gcd(b , a % b);
}

int rightrotate(int a[] , int n , int k)
{
	int g = gcd(n , k);
	
	for(int i = n - 1 ; i >= n - g ; i--)
	{
		int temp = a[i];
		
		int j = i;
		
		while(1)
		{
			int d = j - k;
			
			d = (d + n) % n;
			
			if(d == i)
			break;
			
			a[j] = a[d];
			
			j = d;
		}
		a[j] = temp;
	}
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(a)/sizeof(int);
	
	rightrotate(a , n , 4);
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
	
	return 0;
}

