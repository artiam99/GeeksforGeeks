#include <bits/stdc++.h>
using namespace std;

int Get_Sum(int *BIT , int r)
{
	r++;
	
	int sum = 0;
	
	while(r > 0)
	{
		sum += BIT[r];
		
		r -= (r & -r);
	}
	
	return sum;
}

void Update(int *BIT , int n , int i , int val)
{
	i++;
	
	while(i <= n)
	{
		BIT[i] += val;
		
		i += (i & -i);
	}
}

int* Construct(int a[] , int n)
{
	int* BIT = new int[n+1];
	
	for(int i = 1 ; i <= n ; i++)
	BIT[i] = 0;
	
	for(int i = 0 ; i < n ; i++)
	Update(BIT , n , i , a[i]);
	
	for(int i = 1 ; i <= n ; i++)
	cout << BIT[i] << " ";
	cout << endl;
	
	return BIT;
}

int Query(int* BIT , int l , int r)
{
	return Get_Sum(BIT , r) - Get_Sum(BIT , l-1);
}

int main()
{
	int a[] = {1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5};
	int n = sizeof(a)/sizeof(int);
	
	int* BIT = Construct(a , n);
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
	cout << endl;
	
	cout << Query(BIT , 0 , 7) << endl;
	
	int diff = 6;
	
	a[3] += diff;
	
	Update(BIT , n , 3 , diff);
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
	cout<<endl;
	
	cout << Query(BIT , 2 , 8) << endl;
	
    return 0;
}
