#include<bits/stdc++.h>
using namespace std;
int Min_Cost(vector<int> &a,int n)
{
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(int i = 0 ; i < n ; i++)
	pq.push(a[i]);
	
	int cost = 0;
	
	while(pq.size() > 1)
	{
		int x = 0;
		
		x += pq.top(); pq.pop();
		x += pq.top(); pq.pop();
		
		cost += x;
		
		pq.push(x);
	}
	return cost;
}
signed main()
{
	vector<int> a = {4, 3, 2, 6};
	int n = a.size();
	
	cout<< Min_Cost(a,n) << endl;
    
    return 0;
}
