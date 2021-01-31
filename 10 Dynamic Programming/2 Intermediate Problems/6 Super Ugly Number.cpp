#include<bits/stdc++.h>
using namespace std;
int SuperUgly(vector<int> &a,int n,int N)
{
	vector<int> dp(1,1);
	
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	
	for(int i=0;i<n;i++)
	pq.push({a[i],{a[i],0}});
	
	while(dp.size() != N)
	{
		int mn = pq.top().first;
		int x = pq.top().second.first;
		int mni = pq.top().second.second;
		
		pq.pop();
		
		if(dp[dp.size()-1] < mn)
		dp.push_back(mn);
		
		pq.push({dp[mni+1]*x,{x,mni+1}});
	}
	
	return dp[dp.size()-1];
}
signed main()
{
	vector<int> a = {2,3,5};
	int n = a.size();
	
	int N = 50;
	
	cout<< SuperUgly(a,n,N) <<endl;
    
	return 0;
}

