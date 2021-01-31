#include<bits/stdc++.h>
using namespace std;

int Pair_Count(vector<int> &a , int n)
{
	sort(a.begin() , a.end());
	
	int k = 4 , l = 0, r = n-1 , c = 0;
	
	while(l < r)
	{
		if(a[l] + a[r] == k)
		{
			c++;
			
			l++;
			
			r--;
		}
		
		else if(a[l] + a[r] > k)
		r--;
		
		else
		l++;
	}
	
	return c;
}

signed main()
{
	vector<int> a = {1, 2, 3, 0, 3, 2, 1};
	int n = a.size();
	
	cout << Pair_Count(a , n) << endl;
	
	return 0;
}
