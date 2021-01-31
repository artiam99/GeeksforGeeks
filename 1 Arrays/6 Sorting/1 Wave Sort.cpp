#include<bits/stdc++.h>
using namespace std;

void Wave_Sort(vector<int> &a , int n)
{
	for(int i = 0 ; i < n ; i += 2)
	{
		if(i > 0 && a[i] < a[i-1])
		swap(a[i] , a[i-1]);
		
		if(i < n-1 && a[i] < a[i+1])
		swap(a[i] , a[i+1]);
	}
	
	for(auto i : a)
	cout << i << " ";
	cout << endl;
}

int main()
{
	vector<int> a = {4, 5, 3, 2, 8, 9, 7};
	int n = a.size();
	
	Wave_Sort(a , n);
	
	return 0;
}
