#include<bits/stdc++.h>
using namespace std;

void countingsort(vector<int> &a,int n)
{
	int max = *max_element(a.begin() , a.end());
	int min = *min_element(a.begin() , a.end());

	int range = max - min + 1;
	
	vector<int> c(range);

	for(int i = 0 ; i < n ; i++)
	c[a[i] - min]++;
	
	for(int i = 1 ; i < range ; i++)
	c[i] += c[i-1];
	
	vector<int> b(n);
	
	for(int i = 0 ; i < n ; i++)
	{
		b[c[a[i] - min] - 1] = a[i];
		
		c[a[i] - min]--; 
	}
	
	a = b;
}

int main() 
{
	vector<int> a = {1, 4, 3, 5, 2, 7, 6, -7, -10};
	int n = a.size();
	
	countingsort(a , n);
	
	for(int i = 0 ; i < n ; i++)
	cout << a[i] << " ";
    
	return 0; 
}

