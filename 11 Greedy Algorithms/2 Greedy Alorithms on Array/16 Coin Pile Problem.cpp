#include<bits/stdc++.h>
using namespace std;
int Min_Cost(vector<int> &a,int n,int k)
{
	sort(a.begin(),a.end());
	
	vector<int> p(n);  p[0] = a[0];
		
	for(int i = 1 ; i < n ; i++)
	p[i] = p[i-1] + a[i];
	
	int ans = INT_MAX , prev = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		int pos = upper_bound(a.begin()+i,a.end(),a[i]+k) - a.begin();
		
		if(i > 0 && a[i] != a[i-1])  prev = p[i-1];
		
		ans = min(ans , prev + p[n-1] - p[pos-1] - (n-pos) * (a[i]+k));
	}
	return ans;
}
signed main()
{
	vector<int> a = {1, 5, 2, 1 , 1};
	int n = a.size();
	
	int k = 3;
	
	cout<< Min_Cost(a,n,k) << endl;
	
    return 0;
}
