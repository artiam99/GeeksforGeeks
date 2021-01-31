#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void rearrange(vector<int> &a,int n)
{
	priority_queue<pair<int,int>> pq;
	for(int i=0;i<n;i++)
	pq.push({a[i],i});
	
	int i=0;
	while(pq.size())
	{
		if(i!=pq.top().second)
		{
			a[i++]=pq.top().first;
			pq.pop();
		}
		else
		{
			if(pq.size()>1)
			{
				pair<int,int> x=pq.top(); pq.pop();
				
				a[i++]=pq.top().first; pq.pop();
				
				pq.push(x);
			}
			else
			{
				a[i]=pq.top().first; pq.pop();
				swap(a[i],a[i-1]);
			}
		}
	}
}
signed main()
{
	vector<int> a={ 92, 3, 52, 13, 2, 31, 1 };
	int n=a.size();
	
	rearrange(a,n);
	
	for(auto i:a)
	cout<<i<<" ";
	cout<<endl;
	
	return 0;
}
