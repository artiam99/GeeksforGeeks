#include <bits/stdc++.h> 
using namespace std; 

void shufleArray(int a[] , int n)
{
 	n /= 2;

    int i = n - 1;
    
	for(int j = 2 * n - 1 ; j >= n ; j--)
    {
        a[j] <<= 10;
    
        a[j] |= a[i];
        
        i--;
    }

    i = 0;
    
    for (int j = n ; j < 2 * n ; j++)
    {
        int a1 = a[j] & 1023;
        int a2 = a[j] >> 10;
    
        a[i] = a1;
        
        a[i + 1] = a2;
        
        i += 2;
    }
}

int main()
{
	int a[] = {1, 3, 5, 7, 2, 4, 6, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	shufleArray(a , n);

	for (int i = 0 ; i < n ; i++)
	cout << a[i] << " ";

	return 0;
}

