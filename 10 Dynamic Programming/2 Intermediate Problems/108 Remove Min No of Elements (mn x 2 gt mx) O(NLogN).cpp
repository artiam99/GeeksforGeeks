#include<bits/stdc++.h>
using namespace std;
int MinRemove(vector<int> &a,int n)
{
	sort(a.begin(),a.end());
    
    int ans = INT_MAX;
    
    for(int i = 0 ; i < n ; i++)
    ans = min( ans , i + ( n - (int)(upper_bound(a.begin() + i + 1 , a.end() , a[i]*2) - a.begin()) ) );
    
    return ans;
}
signed main()
{
	vector<int> a = {4,5,100,9,10,11,12,15,200};
	int n = a.size();
	
	cout<< MinRemove(a,n) <<endl;
	
	return 0;
}
