#include<bits/stdc++.h>
using namespace std;

int Find_Rank(vector<int> &a , int n , int x)
{
	int rank = 0;
	
	int cnt;
	
	int prev_sum = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		cnt = upper_bound(a.begin() + i , a.end() , x + prev_sum) - (a.begin() + i);
		
		rank += cnt;
		
		prev_sum = a[i];
	}
	
	return rank;
}

int Kth_Min_Subarr_Sum(vector<int> &a , int n , int k)
{
	for(int i = 1 ; i < n ; i++)
	a[i] += a[i-1];
	
	int l = *min_element(a.begin() , a.end()) , r = a[n-1] , m;
	
	while(l <= r)
	{
		m = ((l + r) >> 1);
		
		if(Find_Rank(a , n , m) >= k)
		r = m - 1;
		
		else
		l = m + 1;
	}
	
	return l;
}

signed main()
{
	vector<int> a = {1, 3, 4, 2, 6, 5};
	int n = a.size();
	int k = 15;
	
	cout << Kth_Min_Subarr_Sum(a , n , k) << endl;

	return 0;
}
