#include<bits/stdc++.h>
using namespace std;
int Maxoffer(vector<int> &h,int n)
{
	int dp1[n] , dp2[n]; dp1[0] = dp2[n-1] = 1;
	
	for(int i=1;i<n;i++)
	{
		dp1[i] = ((h[i] > h[i-1]) ? dp1[i-1] : 0) + 1;
		
		dp2[n-i-1] = ((h[n-i-1] > h[n-i]) ? dp2[n-i] : 0) + 1;
	}
	int cnt = 0;
	
	for(int i=0;i<n;i++)
	cnt += max(dp1[i] , dp2[n-i-1]);
	
	return cnt;
}
signed main()
{
	vector<int> h = {3, 3, 4, 3, 2, 1};
	int n = h.size();
	
	cout<< Maxoffer(h,n) <<endl;
    
	return 0;
}

