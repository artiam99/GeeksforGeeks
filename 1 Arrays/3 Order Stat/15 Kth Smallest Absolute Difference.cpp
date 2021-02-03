#include<bits/stdc++.h>
using namespace std;

int Find_Rank(vector<int> &a , int n , int x)
{
	int rank = 0;
	
	int cnt;
	
	for(int i = 0 ; i < n ; i++)
	{
		cnt = upper_bound(a.begin() + i , a.end() , a[i] + x) - a.begin();
		
		rank += cnt - (i + 1);
	}
	
	return rank;
}

int Kth_Abs_Diff(vector<int> &a , int n , int k)
{
	sort(a.begin() , a.end());
	
	int l = INT_MAX , r = a[n-1] - a[0] , m;
	
	for(int i = 1 ; i < n ; i++)
	l = min(l , a[i-1] - a[i]);
	
	while(l <= r)
	{
		m = l + (r - l) / 2;
		
		if(Find_Rank(a , n , m) >= k)
		r = m - 1;
		
		else
		l = m + 1;
	}
	
	return l;
}

signed main()
{
	vector<int> a = {1, 2, 3, 4, 5, 6};
	int n = a.size();
	int k = 6;
	
	cout << Kth_Abs_Diff(a , n , k) << endl;
	
	return 0;
}
