#include<bits/stdc++.h>
using namespace std;

int getmax(vector<int> &a , int n)
{
	int m = 0;
	
	for(int i = 1 ;  i < n ; i++)
	if(a[i] > a[m])
	m = i;
	
	return a[m];
}

void coutntingsort(vector<int> &a , int n , int e)
{
	vector<int> b(10);
	
	for(int i = 0 ; i < n ; i++)
	b[(a[i] / e) % 10]++;
	
	for(int i = 1 ; i < 10 ; i++)
	b[i] += b[i-1];
	
	vector<int> p(n);
	
	for(int i = n-1 ; i >= 0 ; i--)//To maintain the previous order of same priority element counting sort will be done backward
	{
		p[b[(a[i] / e) % 10] - 1] = a[i];
		
		b[(a[i] / e) % 10]--;
	}
	
	for(int i = 0 ; i < n ; i++)
	a[i] = p[i];
}


void radixsort(vector<int> &a , int n)
{
	int m = getmax(a , n);
	
	for(int i = 1 ; m / i > 0 ; i *= 10)
	coutntingsort(a,n,i);
}

int main() 
{
	vector<int> a = {1, 4, 3, 5, 2, 7, 2, 6, 100, 23};
	int n = a.size();
	
	radixsort(a , n);
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
	cout << endl;
    
	return 0; 
} 
