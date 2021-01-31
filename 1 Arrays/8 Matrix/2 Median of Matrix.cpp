#include<bits/stdc++.h>
using namespace std;

int Median(vector<vector<int>> &a , int r , int c)
{
	int mx = INT_MIN;
	int mn = INT_MAX;
	
	for(int i = 0 ; i < r ; i++)
	{
		if(a[i][0] < mn)
		mn = a[i][0];
		
		if(a[i][c-1] > mx)
		mx = a[i][c-1];
	}

	int desired = (r * c + 1) / 2;  //because there must be n/2 elements lesser than median

	while(mn < mx)
	{
		int md = mn + (mx - mn) / 2;
		
		int lessnumbers = 0;
		
		for(int i = 0 ; i < r ; i++)
		lessnumbers += upper_bound(a[i].begin() , a[i].end() , md) - a[i].begin();
		
		if(lessnumbers < desired)
		mn = md + 1;
		
		else
		mx = md;
	}
	
	return mn;
}

signed main()
{
	vector<vector<int>> a = { {1, 3, 5},
							  {2, 6, 9},
							  {3, 6, 9} };
	int r = a.size();
	int c = a[0].size();
	
	cout << Median(a , r , c) << endl;
	
	return 0;
}
