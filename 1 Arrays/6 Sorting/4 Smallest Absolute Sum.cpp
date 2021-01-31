#include<bits/stdc++.h>
using namespace std;

void Smallest_Abs_Sum(vector<int> &a , int n)
{
	int l = 0 , r = n-1 , sum = 1000000;
	
	sort(a.begin() , a.end());
	
	int lm , rm;
	
	while(l < r)
	{
	    if(abs(sum) > abs(a[l] + a[r]))
	    {
	    	lm = l;
	    	rm = r;
	    	sum = a[l] + a[r];
		}
		
	    if(a[l] + a[r] < 0)
	    l++;
	    
		else
	    r--;
    }
    
	cout << "Elements : " << a[lm] << " " << a[rm] << " Sum : " << sum << endl;
}

int main()
{
    vector<int> a = {-18, -14, -68, -4, 3, -34};
	int n = a.size();
	
	Smallest_Abs_Sum(a , n);
	
	return 0;
}
