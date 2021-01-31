#include<bits/stdc++.h>
using namespace std;
int MaxProdSubarr(vector<int> &a,int n)
{
	int ans = INT_MIN;
	
	int max_val = 1;
	
	int min_val = 1;
	
	int prev_max;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] > 0)
		{
			max_val *= a[i];
	
			min_val = min(1 , a[i] * min_val);  // if min_val is negative then it will be updated
		}
		else if(a[i] < 0)
		{
			prev_max = max_val;
			
			max_val = min_val * a[i];  // As it becomes Positive
			
			min_val = prev_max * a[i];  // As it becomes Negative
		}
		else
		{
			max_val = 0;
			
			min_val = 1;
		}
		
		ans = max(ans , max_val);
		
		if(max_val <= 0)  // if its 0 or negative we cannot decrease it
		max_val = 1;
	}
	return ans;
}
signed main()
{
	vector<int> a = {-2, -3, 0, -2, -40};
	int n = a.size();
	
	cout<< MaxProdSubarr(a,n) <<endl;
    
	return 0;
}
