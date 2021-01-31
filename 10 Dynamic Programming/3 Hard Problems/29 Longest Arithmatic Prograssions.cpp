#include<bits/stdc++.h>
using namespace std;
int No_of_AP(vector<int> &a,int n)
{
	int ans = 1;
        
    int mn = *min_element(a.begin(),a.end());
    int mx = *max_element(a.begin(),a.end());
    
    int dp[n] , Sum[10001];
    
    for(int d = mn-mx ; d <= mx-mn ; d++)
    {
        memset(Sum,0,sizeof(Sum));
        
        for(int i = 0 ; i < n ; i++)
        {
            dp[i] = 0;
            
            if(a[i]-d >= 1 && a[i]-d <= 10000)
            dp[i] += Sum[a[i]-d];
            
            Sum[a[i]] = dp[i]+1;
            
            ans = max(ans , Sum[a[i]]);
        }
    }
    return ans;
}
signed main()
{
	vector<int> a = {1, 2, 3, 4, 5}; // 1 <= a[i] <= 100
	int n = a.size();
	
	cout<< No_of_AP(a,n) <<endl;
    
	return 0;
}
