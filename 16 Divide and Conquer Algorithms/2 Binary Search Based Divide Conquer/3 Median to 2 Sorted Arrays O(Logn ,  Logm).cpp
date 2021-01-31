#include<bits/stdc++.h>
using namespace std;
double solve(vector<int> &a , int n , vector<int> &b , int m , int start , int end , int tot)
{
    if(start <= end)
	{
        int partX = (start + end) / 2;
        
        int partY = tot - partX;

        int maxLeftX = (partX <= 0) ? INT_MIN : a[partX -1];
        
        int minRightX = (partX >= n) ? INT_MAX : a[partX];
        
		int maxLeftY = (partY <= 0) ? INT_MIN : b[partY -1];
        
		int minRightY = (partY >= m) ? INT_MAX : b[partY];
        
        if( maxLeftX <= minRightY  && maxLeftY <= minRightX )  return (((n + m) & 1) ? max(maxLeftX , maxLeftY) : (max(maxLeftX , maxLeftY) + min(minRightX , minRightY)) / 2.0);
        
        else if( maxLeftX > minRightY)  return solve(a, n , b , m , start , partX-1 , tot);
        
		else  return solve(a , n , b , m , partX+1 , end , tot);
    }
    return -1;
}
double Median(vector<int> &a,int n,vector<int> &b,int m)
{   
	int tot = (n + m + 1) / 2;
    
	if(n > m)  return solve(b, m , a , n , 0 , m , tot);            
    
    return solve(a , n , b , m , 0 , n , tot);
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
