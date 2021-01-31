#include<bits/stdc++.h>
using namespace std;
void Max_Min_Cost(vector<int> &a,int n,int k)
{
	sort(a.begin(),a.end());
	    
    int r = n , mn = 0;
    
    for(int i = 0 ; i < r ; i++)
    mn += a[i] , r -= k;
    
    int l = -1 , mx = 0;
    
    for(int i = n-1 ; i > l ; i--)
    mx += a[i] , l += k;
    
    cout<< mn << " " << mx <<endl;
}
signed main()
{
    vector<int> a = {3 , 2, 1, 4};
    int n = a.size();
    
    int k = 2;
    
    Max_Min_Cost(a,n,k);
    
    return 0;
}
