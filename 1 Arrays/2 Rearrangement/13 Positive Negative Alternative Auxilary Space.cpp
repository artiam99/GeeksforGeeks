#include <bits/stdc++.h> 
using namespace std;

void Pos_Neg_Alt(vector<int> &a , int n)
{
	vector<int> b , c;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] < 0)  b.push_back(a[i]);
		
		else  c.push_back(a[i]);
	}
	
	int i = 0 , j = 0;
	
	int p = b.size();
	
	int q = c.size();
	
	int k = 0;
	
	while(i < p && j < q)
	{
		a[k++] = b[i++];
		
		a[k++] = c[j++];
	}
	
	while(i < p)
	a[k++] = b[i++];
	
	while(j < q)
	a[k++] = c[j++];
	
	for(auto i : a)
	cout << i << " ";
}

int main() 
{
	vector<int> a = {2, 5, 4, -1, 6, 3, -8, -9};
	int n = a.size();
	
	Pos_Neg_Alt(a , n);
	
	return 0; 
} 

