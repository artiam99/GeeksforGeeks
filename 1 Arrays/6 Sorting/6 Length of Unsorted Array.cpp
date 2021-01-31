#include<bits/stdc++.h>
using namespace std;

void Unsorted_Array(vector<int> &a , int n)
{
	int l = 0 , r = n-1;
	
	while(l < n-1 && a[l] <= a[l+1])
	l++;
	
	while(r > 0 && a[r] >= a[r-1])
	r--;
	
	if(l >= r)
	cout << 0 << " " << 0 << endl;  // l==n-1   &&   r==0  only one case where l>=r  
	
	else
	{
		int mx = *max_element(a.begin() + l , a.begin() + r + 1);
    	
		int mn = *min_element(a.begin() + l , a.begin() + r + 1); 
    	
		for(int i = l - 1 ; i >= 0 ; i--)
    	if(a[i] > mn)
    	l = i;
    	
    	for(int i = r + 1 ; i < n ; i++)
    	if(a[i] < mx)
	    r = i;
	    
     	cout << l << " " << r << endl;
	}
}

signed main()
 {

	vector<int> a = {1, 3, 6, 3, 7, 2, 8, 5, 3, 8, 9};
	int n = a.size();
	
	Unsorted_Array(a , n);
	
	return 0;
}
