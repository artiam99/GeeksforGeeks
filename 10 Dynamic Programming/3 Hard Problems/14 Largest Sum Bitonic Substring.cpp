#include<bits/stdc++.h>
using namespace std;
int MaxSum(vector<int> &a,int n)
{
	int l = 0 , mx = 0 , sum = 0;
	    
    while(l < n)
    {
        sum += a[l];
        
        mx = max(mx , sum);
        
        if(l < n-1 && a[l] == a[l+1])
        sum = 0;
        
        if(l < n-1 && a[l] > a[l+1])
        {
	        while(l < n-1 && a[l] > a[l+1])
	        {
	            sum += a[l+1];
	            
	            l++;
	        }
        
            mx = max(mx , sum);
            
            if(l < n-1 && a[l] < a[l+1])
            l--;
            
            sum = 0;
        }
        
        l++;
    }
    return mx;
}
signed main()
{
	vector<int> a = {5, 3, 9, 2, 7, 6, 4};
	int n = a.size();
	
	cout<< MaxSum(a,n) <<endl;
    
	return 0;
}
