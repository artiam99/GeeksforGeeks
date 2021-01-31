#include<bits/stdc++.h>
using namespace std;
int MSBS(vector<int> &a,int n)
{
	vector<int> dpl = a,dpr = a;
	
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
	{
		if(a[j] < a[i])  dpl[i] = max(dpl[i] , dpl[j] + a[i]);
		
		if(a[n-j-1] < a[n-i-1])  dpr[n-i-1] = max(dpr[n-i-1] , dpr[n-j-1] + a[n-i-1]);
	}
	
	int mx = dpl[0] + dpr[0] - a[0];
	
	for(int i=1;i<n;i++)
	mx = max(mx , dpl[i] + dpr[i] - a[i]);
	
	return mx;
}
signed main()
{
	vector<int> a = {1, 15, 51, 45, 33, 100, 12, 18, 9};
	int n = a.size();
    
    cout<< MSBS(a,n) <<endl;
    
	return 0;
}
