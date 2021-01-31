#include<bits/stdc++.h>
using namespace std;

int Partition(int a[] , int l , int r)  //................O(n) .....see proof in coremen
{
	int k = l;
	
	for(int i = l ; i < r ; i++)
	if(a[i] < a[r])
	{
		swap(a[i] , a[k]);
		
		k++;
	}
	
	swap(a[k] , a[r]);
	
	return k;
}

int Rand_Partition(int a[] , int l , int r)
{
	int p = rand() % (r - l + 1) + l;
	
	swap(a[p] , a[r]);
	
	return Partition(a , l , r);
}

int Kth_Smallest(int a[] , int l , int r , int k)
{
	if(k > 0 && k <= r - l + 1)
	{
		int p = Rand_Partition(a , l , r);
		
		if(p - l + 1 == k)  return a[p];
		
		if(p - l + 1 > k)  return Kth_Smallest(a , l , p - 1 , k);
		
		return Kth_Smallest(a , p + 1 , r , k - p + l - 1);
	}
}

int main() 
{
	srand(time(NULL));
	
	int a[] = {21, 13, 11, 15, 16, 14, 17};
	int n = sizeof(a)/sizeof(int);
	
	cout << Kth_Smallest(a , 0 , n - 1 , 3) << endl;
    
	return 0; 
}
