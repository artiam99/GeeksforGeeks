#include<bits/stdc++.h>
using namespace std;
int findkth(vector<int> &a,vector<int> &b,int n,int m,int k)
{
    int l = min(a[0] , b[0]) , r = max(a[n-1] , b[m-1]);
    
    while(l <= r)
    {
        int mid = (r + l) >> 1;
        
        if(upper_bound(a.begin(),a.end(),mid) - a.begin() + upper_bound(b.begin(),b.end(),mid) - b.begin() >= k)  r = mid - 1;
        
        else  l = mid + 1;
    }
    
    return l;
}
double Median(vector<int> &a,int n,vector<int> &b,int m)
{
	if(!n && !m)  return -1;
        
    if(!n)
    {
        if(m & 1)  return b[m/2];
            
        return (b[m/2] + b[m/2 - 1]) / 2.0;
    }
    
    if(!m)
    {
        if(n & 1)  return a[n/2];
        
        return (a[n/2] + a[n/2 - 1]) / 2.0;
    }
    
    int k = (m + n) / 2;
    
    if((m+n) & 1)  return findkth(a,b,n,m,k+1);
    
    return (findkth(a,b,n,m,k) + findkth(a,b,n,m,k+1)) / 2.0;
}
signed main()
{
	vector<int> a = {1, 2, 3, 5};
	int n = a.size();
	
	vector<int> b = {6, 8, 10};
	int m = b.size();
	
	cout << Median(a,n,b,m) << endl;
	
	return 0;
}
