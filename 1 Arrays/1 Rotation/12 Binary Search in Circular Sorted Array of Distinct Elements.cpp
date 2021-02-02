#include <bits/stdc++.h>
using namespace std;

int Binary_Search(vector<int> &a , int n , int x)
{
	int l = 0 , r = n - 1 , m;
	
	while(l <= r)
	{
		m = l + (r - l) / 2;
		
		if(a[m] == x)
		return m;
		
		else if(a[m] < a[r])
		{
			if(a[m] < x && a[r] >= x)
			l = m + 1;
			
			else
			r = m - 1;
		}
		
		else
		{
			if(a[m] > x && a[l] <= x)
			r = m - 1;
			
			else
			l = m + 1;
		}
	}
	return -1;
}

int main()
{
    vector<int> a = {3, 4, 5, 1, 2};
    int n = a.size();
    
    cout << Binary_Search(a , n , 4) << endl;
	
	return 0;
}

