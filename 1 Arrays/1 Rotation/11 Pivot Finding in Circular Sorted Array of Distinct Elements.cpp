#include <bits/stdc++.h>
using namespace std;

int Pivot(vector<int> &a , int n)
{
	int l = 0 , r = n-1 , m , prev , next;
	
	while(l <= r)
	{
		if(a[l] <= a[r])  // First or Same Element
		return l;
		
		m = (l + r) / 2;
		
		prev = (m - 1 + n) % n;
		
		next = (m + 1) % n;
		
		if(a[m] < a[prev] && a[m] < a[next])
		return m;
		
		else if(a[m] < a[r])
		r = m - 1;
		
		else
		l = m + 1;
	}
	
	return -1;
}

int main()
{
    vector<int> a = {3, 4, 5, 1, 2};
    int n = a.size();
    
    cout << Pivot(a , n) << endl;
	
	return 0;
}
