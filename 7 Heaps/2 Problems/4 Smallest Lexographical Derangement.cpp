#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
signed main()
{
	int n=10;
	vector<int> a(n);
	
	iota(a.begin(),a.end(),0);
	
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++)
	pq.push(a[i]);
	
	int i=0;
	while(pq.size())
	{
		if(i!=pq.top())
		{
			a[i++]=pq.top();
			pq.pop();
		}
		else
		{
			if(pq.size()>1)
			{
				int x=pq.top();pq.pop();
				a[i++]=pq.top();pq.pop();
				pq.push(x);
			}
			else
			{
				a[i]=pq.top();pq.pop();
				swap(a[i],a[i-1]);
			}
		}
	}
	
	for(auto i:a)
	cout<<i+1<<" ";
	cout<<endl;
	return 0;
}
