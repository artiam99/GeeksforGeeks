#include<bits/stdc++.h>
using namespace std;
void MaxMinProd(vector<int> &a,int n)
{
	if(n==1)
	{
		cout<< a[0] << " " << a[0] <<endl;
		
		return;
	}
	
	int mx = INT_MIN , mn = INT_MAX;
	
	int max_neg = INT_MIN , min_pos = INT_MAX , cnt_neg = 0 , cnt_zero = 0 , prod = 1;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] == 0)
		{
			cnt_zero++;
			
			continue;
		}
		
		if(a[i] < 0)
		{
			cnt_neg++;
			
			max_neg = max(max_neg , a[i]);
		}
		
		if(a[i] > 0)
		min_pos = min(min_pos , a[i]);
		
		prod *= a[i];
	}
	
	if(mn == INT_MAX)
	{
		if(cnt_zero == n || (cnt_neg == 0 && cnt_zero > 0))  mn = 0;
		
		else if(cnt_neg == 0)  mn = min_pos;
		
		else if(!(cnt_neg & 1) && cnt_neg != 0)  mn = prod / max_neg;
		
		else  mn = prod;
	}
	
	if(mx == INT_MIN)
	{
		if(cnt_zero == n)  mx = 0;
	
		else if(cnt_neg & 1)
		{
			if(cnt_neg == 1 && cnt_zero > 0 && cnt_zero + cnt_neg == n)  mx = 0;
			
			else  mx = prod / max_neg;
		}
		
		else mx = prod;
	}
	
	cout<< mx << " " << mn <<endl;
}
signed main()
{
	vector<int> a = {-1, -1, -2, 4, 3, 0};
	int n = a.size();
	
	cout<< "Max Prod Subset && Min Prod Subset : " ;
	
	MaxMinProd(a,n);
	
	return 0;
}
