#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
int MaxSum(vector<int> &a,int n)
{
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(auto i:a)
	pq.push(i);
	
	int x=0,y=0;
	
	while(pq.size())
	{
		x= x *10 + pq.top(); pq.pop();
		
		if(pq.size())
		{
			y =y*10 +pq.top(); pq.pop();
		}
	}
	return x+y;
}
signed main()
{
	vector<int> a={6, 8, 4, 5, 2, 3};
	int n=a.size();
	
	cout<<MaxSum(a,n)<<endl;
	
	return 0;
}
