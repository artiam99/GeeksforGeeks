#include<bits/stdc++.h>
using namespace std;

void Update(vector<int> &a , int l , int r , int x)
{
	a[l] += x;
	a[r+1] -= x;
}

void Print_Array(vector<int> &a)
{
	for(int i = 1 ; i < a.size() ; i++)
	a[i] = a[i-1] + a[i];
	
	for(auto i : a)
	cout << i << " ";
	cout << endl;
}

int main()
{
	vector<int> a = {10, 5, 20, 40};
	int n = a.size();
	
	for(int i = n-1 ; i > 0 ; i--)
	a[i] -= a[i-1];
	
	Update(a , 0 , 1 , 10);
    
	Print_Array(a);
    
    Update(a , 1 , 3 , 20);
    
	Update(a , 2 , 2 , 30);
    
	Print_Array(a);
	
	return 0;
}
