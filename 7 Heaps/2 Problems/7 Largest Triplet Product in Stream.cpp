#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void LargestTriplet(vector<int> &a,int n)
{
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(int i=0;i<n;i++)
	{
		if(pq.size()<3)
		pq.push(a[i]);
		
		else if(pq.top()<a[i])
		{
			pq.pop();
			pq.push(a[i]);
		}
		
		if(pq.size()<3)
		cout<<-1<<endl;
		else
		{
			int x=pq.top();pq.pop();
			int y=pq.top();pq.pop();
			int z=pq.top();pq.pop();
			
			cout<<x*y*z<<endl;
			pq.push(x);
			pq.push(y);
			pq.push(z);
		}
	}
}
signed main()
{
	vector<int> a={1,2,3,4,5};
	int n=a.size();
	
	LargestTriplet(a,n);
	
	return 0;
}
