#include<bits/stdc++.h>
using namespace std;

void Transpose(vector<vector<int>> &a , int n , int m)
{
	for(int i = 0 ; i < n ; i++)
	for(int j = i ; j < m ; j++)
	swap(a[i][j] , a[j][i]);
}

void Reverse(vector<vector<int>> &a , int n , int m)
{
	for(int i = 0 ; i < m ; i++)
	{
		int l = 0 , r = n-1;
		
		while(l < r)
		{
			swap(a[l][i] , a[r][i]);
			
			l++;
			
			r--;
		}
	}
}

void Rotate180(vector<vector<int>> &a , int n , int m)
{
	Transpose(a , n , m);
	Reverse(a , n , m);
	
	Transpose(a , n , m);
	Reverse(a , n , m);
}

signed main()
{
	vector<vector<int>> a = { {1, 2, 3, 4, 5},
							  {2, 3, 4, 5, 6},
							  {3, 4, 5, 6, 7},
							  {4, 5, 6, 7, 8},
							  {6, 7, 8, 9, 1} };
	int n = a.size();
	int m = a[0].size();
	
	for(auto i : a)
	{
		for(auto j : i)
		cout << j << " ";
		cout << endl;
	}
	cout << endl << endl;
	
	Rotate180(a , n , m);
	
	for(auto i : a)
	{
		for(auto j : i)
		cout << j << " ";
		cout << endl;
	}
	cout << endl << endl;
	
	return 0;
}
