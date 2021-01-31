#include<bits/stdc++.h>
using namespace std;

int Step_Count(vector<int> &a , int n)
{
	int l = 0 , r = n-1;
	
	int c = 0;
	
	while(l <= r)
	{
		if(a[l] == a[r])
		{
			l++;
			
			r--;
		}
		
		else if(a[l] > a[r])
		{
			a[r-1] += a[r];
			
			r--;
			
			c++;
		}
		
		else if(a[l] < a[r])
		{
			a[l+1] += a[l];
			
			l++;
			
			c++;
		}
	}
	return c;
}

int main()
{
	vector<int> a = {5, 1, 4, 5};
	int n = a.size();
	
	cout << Step_Count(a , n) << endl;
	
	return 0;
}
