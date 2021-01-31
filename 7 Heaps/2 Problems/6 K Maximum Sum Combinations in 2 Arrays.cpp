#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void printKMaxSum(vector<int> &a,vector<int> &b,int n,int k)
{
	sort(a.begin(),a.end(),greater<int>());
	sort(a.begin(),a.end(),greater<int>());
	
	priority_queue<pair<int,pair<int,int>>> pq;
	
	set<pair<int,int>> s;
	
	pq.push({a[0]+b[0],{0,0}});
	s.insert({0,0});
	
	for(int i=0;i<k;i++)
	{
		cout<<pq.top().first<<endl;
		
		int l=pq.top().second.first;
		int r=pq.top().second.second;
		
		pq.pop();
		
		if(l+1<n)
		{
			if(s.find({l+1,r})==s.end())
			{
				pq.push({a[l+1]+b[r],{l+1,r}});
				s.insert({l+1,r});
			}
		}
		if(r+1<n)
		{
			if(s.find({l,r+1})==s.end())
			{
				pq.push({a[l]+b[r+1],{l,r+1}});
				s.insert({l,r+1});
			}
		}
	}
}
signed main()
{
	vector<int> a={4, 2, 5, 1};
	vector<int> b={8, 0, 3, 5};
	int n=a.size();
	int k=3;
	
	printKMaxSum(a,b,n,k);
	
	return 0;
}
