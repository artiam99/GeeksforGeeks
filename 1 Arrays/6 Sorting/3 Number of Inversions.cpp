#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int> &a , int l , int r , int &c)
{
	int m = l + (r - l) / 2;
	
	int n1 = m - l + 1;
	int n2 = r - m;
	
	vector<int> L(n1);
	vector<int> R(n2);
	
	for(int i = 0 ; i < n1 ; i++)
	L[i] = a[i+l];

	for(int i = 0 ; i < n2 ; i++)
	R[i] = a[i+m+1];
	
	int i = 0 , j = 0 , k = l;
	
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		a[k++] = L[i++];
		
		else if(L[i] > R[j])
		{
			a[k++] = R[j++];
			
			c += m - (l+i) + 1;
		}
	}
	
	while(i < n1)
	a[k++] = L[i++];
	
	while(j < n2)
	a[k++] = R[j++];
}

void Mergesort(vector<int> &a , int l , int r , int &c)
{
	if(l < r)
	{
		int m = l + (r - l) / 2;
		
		Mergesort(a , l , m , c);
		
		Mergesort(a , m + 1 , r , c);
		
		Merge(a , l , r , c);
	}
}

int Inversion(vector<int> &a , int n)
{
	int c = 0;
	
	Mergesort(a , 0 , n-1 , c);
	
	return c;
}

int main()
{
	vector<int> a = {5, 1, 4, 2, 3};
	int n = a.size();
	
	cout << Inversion(a , n) << endl;
	
	return 0;
}
