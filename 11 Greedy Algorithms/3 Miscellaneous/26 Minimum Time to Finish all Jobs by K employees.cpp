#include<bits/stdc++.h>
using namespace std;
int Min_Time(vector<int> &a,int n,int K,int T)
{
	sort(a.begin(),a.end(),greater<int>());
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	int mx = INT_MIN;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(pq.size() < K)
		{
			pq.push(a[i]);
			
			mx = max(mx , a[i]);
		}
		else
		{
			int nw = pq.top() + a[i];
			
			pq.pop();
			
			pq.push(nw);
			
			mx = max(mx , nw);
		}
	}
	
	return mx * T;
}
signed main()
{
	vector<int> a = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	int n = a.size();
	int K = 3;
	int T = 1;
	
	cout<< Min_Time(a,n,K,T) << endl;
	
    return 0;
}
