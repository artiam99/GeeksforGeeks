#include<bits/stdc++.h>
using namespace std;
int L01S(vector<int> &a,int n)
{
	unordered_map<int,int> m;
	int mx=1;
	
	for(int i=0;i<n;i++)
	{
		int len=0;
		
		if(m.find(a[i]-1) != m.end() && len < m[a[i]-1])
		len = m[a[i]-1];
		
		if(m.find(a[i]) != m.end() && len < m[a[i]])
		len = m[a[i]];
		
		if(m.find(a[i]+1) != m.end() && len < m[a[i]+1])
		len = m[a[i]+1];
		
		m[a[i]] = len + 1;
		
		mx = max(mx , m[a[i]]);
	}
	return mx;
}
signed main()
{
	vector<int> a = {-2, -1, 5, -1, 4, 0, 3};
	int n = a.size();
    
    cout<< L01S(a,n) <<endl;
    
	return 0;
}
