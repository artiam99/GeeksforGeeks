#include<bits/stdc++.h>
using namespace std;
int Min_Diff(vector<int> &a,int n)
{
	sort(a.begin(),a.end());
	
	int mx = INT_MIN , mn = INT_MAX;
	
	for(int i = 0 , j = n-1 ; i < j ; i++ , j--)
	mx = max(mx , a[i]+a[j]) , mn = min(mn , a[i]+a[j]);
	
	return mx - mn;
}
signed main()
{
	vector<int> a = {2, 6, 4, 3};
	int n = a.size();
	
	cout<< Min_Diff(a,n) << endl;
    
    return 0;
}
