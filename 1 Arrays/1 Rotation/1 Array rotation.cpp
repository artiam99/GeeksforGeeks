#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b)
{
	if(b == 0)  return a;
	
	return gcd(b , a % b);
}

void leftrotate(int a[] , int n , int d)  //directly sending to right position ....theta(n)
{
	d %= n;
	
	int g = gcd(n , d);
	
	for(int i = 0 ; i < g ; i++)
	{
		int t = a[i];
		
		int j = i;
		
		while(1)
		{
			int k = (j + d) % n;
			
			if(k == i)
			break;
			
			a[j] = a[k];
			
			j = k;
		}
		a[j] = t;
	}
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	int n = sizeof(a)/sizeof(int);
	
	leftrotate(a , n , 3);
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
	
	return 0;
}

