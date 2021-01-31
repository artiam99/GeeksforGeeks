#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
signed main()
{	
	vector<int> a={4,2,6,3};
	int n=a.size();
	
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(auto i:a)
	pq.push(i);
	
	int s=0,x;
	
	while(pq.size()>1)
	{
		x=0;
		x+=pq.top();pq.pop();
		x+=pq.top();pq.pop();
		s+=x;
		pq.push(x);
	}
	
	cout<<s<<endl;
	
	return 0;
}
