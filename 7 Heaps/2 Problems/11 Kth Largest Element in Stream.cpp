#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void PrintStream(vector<int> &a,int n,int k)
{
	priority_queue<int,vector<int>,greater<int>> pq;
	
	for(int i=0;i<n;i++)
	{
		if(pq.size()<k)
		pq.push(a[i]);
		
		else if(pq.top()<a[i])
		{
			pq.pop();
			pq.push(a[i]);
		}
		if(pq.size()<k)
		cout<<-1<<endl;
		else
		cout<<pq.top()<<endl;
	}
}
signed main()
{
	vector<int> a={1,2,3,4,5,6};
	int n=a.size();
	int k=4;
	
	PrintStream(a,n,k);
	
	return 0;
}
