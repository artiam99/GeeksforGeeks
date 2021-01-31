#include<bits/stdc++.h>
using namespace std;
int Min_Updates(vector<int> &a,int n)
{
	priority_queue<int,vector<int>,greater<int>> pq;
	
	int sum = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(pq.size() && pq.top() < a[i])
		{
			sum += a[i] - pq.top();
			
			pq.pop();
			
			pq.push(a[i]);
		}
		pq.push(a[i]);
	}
	return sum;
}
signed main()
{
	vector<int> a = {1, 7, 2, 6, 2, 3, 5, 6, 6};
	int n = a.size();
	
	cout<< Min_Updates(a,n) << endl;
	
    return 0;
}
