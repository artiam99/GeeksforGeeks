#include<bits/stdc++.h>
using namespace std;

int Find_Rank(vector<int> &a , int n , int x)
{
	int rank = 0;
	
	int cnt;
	
	int prev_sum = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		cnt = lower_bound(a.begin() , a.end() , x + prev_sum) - a.begin();
		
		rank += n - cnt;
		
		prev_sum = a[i];
	}
	
	return rank;
}

int Kth_Max_Subarr_Sum(vector<int> &a , int n , int k)
{
	for(int i = 1 ; i < n ; i++)
	a[i] += a[i-1];
	
	int l = 0 , r = a[n-1] , m;
	
	while(l <= r)
	{
		
		m = ((l + r) >> 1);
		
		if(Find_Rank(a , n , m) >= k)
		l = m + 1;
		
		else
		r = m - 1;
	}
	
	return r;
}

signed main()
{
	vector<int> a = {1, 3, 4, 2, 6, 5};
	int n = a.size();
	int k = 6;
	
	cout << Kth_Max_Subarr_Sum(a , n , k) << endl;
	
	return 0;
}
