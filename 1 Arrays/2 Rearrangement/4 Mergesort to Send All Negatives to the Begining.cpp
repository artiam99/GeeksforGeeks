#include <bits/stdc++.h> 
using namespace std;

void rotate(vector<int> &a , int l , int r , int m)
{
	int x = r - m;
	
	int g = __gcd((r - l + 1) , x);
	
	int i = r;
	
	while(i >= r - g + 1)
	{
		int temp = a[i];
		
		int j = i;
		
		while(1)
		{
			int k = j - x;
			
			if(k < l)
			k = r - (l - k - 1);
			
			if(k == i)
			break;
			
			a[j] = a[k];
			
			j = k;
		}
		
		a[j] = temp;
		
		i--;
	}
}

void merge(vector<int> &a , int l , int r , int m)
{
	int i = l;
	
	int j = m + 1;
	
	while(i <= m && a[i] < 0)
	i++;
	
	while(j <= r && a[j] < 0)
	j++;
	
	rotate(a , i , j-1 , m);
}

void mergesort(vector<int> &a , int l , int r)
{
	if(l < r)
	{
		int m = l + (r - l) / 2;
		
		mergesort(a , l , m);
		
		mergesort(a , m + 1 , r);
		
		merge(a , l , r , m);
	}
}

int main()
{
	vector<int> a = {2, 4, 3, 5, -8, -6, 8, 9, -3, 7, 2, -1};
	
	int n = a.size();
	
	mergesort(a , 0 , n - 1);
	
	for(auto i : a)
	cout << i << " ";
	
	return 0; 
}
