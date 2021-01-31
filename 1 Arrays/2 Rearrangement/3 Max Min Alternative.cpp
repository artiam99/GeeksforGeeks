#include <bits/stdc++.h>
using namespace std;

void rearrange(int a[] , int n)
{
	int maxi = n - 1 , mini = 0;
	
	int maxe = a[n-1] + 1;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(i % 2 == 0)
		{
			a[i] += (a[maxi] % maxe) * maxe;
			
			maxi--;
		}
		else
		{
			a[i] += (a[mini] % maxe) * maxe;
			
			mini++;
		}
	}
	
	for(int i = 0 ; i < n ; i++)
	a[i] = a[i] / maxe;
}

int main()
{

    int a[] = {10, 20, 30, 50, 60, 100, 110};
    int n = sizeof(a)/sizeof(int);
    
	rearrange(a , n);
    
	for(int i = 0 ; i < n ; i++)
    cout << a[i] << " ";
    
	return 0;
}
