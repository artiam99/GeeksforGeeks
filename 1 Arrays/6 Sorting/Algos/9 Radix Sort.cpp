#include<bits/stdc++.h>
using namespace std;

void coutntingsort(vector<int> &a , int n , int e)
{
	vector<int> c(10);
	
	for(int i = 0 ; i < n ; i++)
	c[(a[i] / e) % 10]++;
	
	for(int i = 1 ; i < 10 ; i++)
	c[i] += c[i-1];
	
	vector<int> p(n);
	
	for(int i = n - 1 ; i >= 0 ; i--) // To maintain the previous order of same priority element counting sort will be done backward
	{
		p[c[(a[i] / e) % 10] - 1] = a[i];
		
		c[(a[i] / e) % 10]--;
	}
	
	a = p;
}


void radixsort(vector<int> &a , int n)
{
	int m = *max_element(a.begin() , a.end());
	
	for(int i = 0 ; i < floor(log10(n)) + 1 ; i++)
	coutntingsort(a , n , pow(10 , i));
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
