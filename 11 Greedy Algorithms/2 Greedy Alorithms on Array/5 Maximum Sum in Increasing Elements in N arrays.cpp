#include<bits/stdc++.h>
using namespace std;
int Max_Sum(vector<vector<int>> &a,int n,int m)
{
	int sum = 0 , lim = INT_MAX;
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		int mx = INT_MIN;
		
		for(int j = 0 ; j < m ; j++)
		if(a[i][j] < lim && a[i][j] > mx)
		mx = a[i][j];
		
		if(mx == INT_MIN)
		return 0;
		
		sum += mx;
		
		lim = mx;
	}
	return sum;
}
signed main()
{
	vector<vector<int>> a = { {1, 7, 3, 4},
                		      {4, 2, 5, 1},
              		 	      {9, 5, 1, 8} };
    int n = a.size();
    int m = a[0].size();
	
	cout<< Max_Sum(a,n,m) << endl;
	
	return 0;
}
