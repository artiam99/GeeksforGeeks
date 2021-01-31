#include<bits/stdc++.h>
using namespace std;
int Max_Stocks(vector<int> &arr,int n,int k)
{
	vector<pair<int,int>> a(n);
	
	for(int i = 0 ; i < n ; i++)
    a[i].first = arr[i] , a[i].second = i+1;
	
    sort(a.begin(),a.end());
    
    int ans = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        int x = floor(k/(double)a[i].first);
        
        ans += min(x,a[i].second);
        
        k -= min(x,a[i].second) * a[i].first;
    }
    return ans;
}
signed main()
{
    vector<int> a = {10 , 7 , 19};
    int n = a.size();
    int k = 45;
    
    cout<< Max_Stocks(a,n,k) <<endl;
    
    return 0;
}
