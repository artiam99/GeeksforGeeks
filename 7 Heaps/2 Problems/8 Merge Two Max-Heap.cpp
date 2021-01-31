#include<bits/stdc++.h>
using namespace std;
#define int long long
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
void heapify(vector<int> &a,int n,int i)
{
	int mx=i;
	int l=i*2+1;
	int r=i*2+2;
	
	if(l<n && a[l]>a[mx])
	mx=l;
	
	if(r<n && a[r]>a[mx])
	mx=r;
	
	if(mx!=i)
	{
		swap(a[i],a[mx]);
		heapify(a,n,mx);
	}
}
void extract_top(vector<int> &a,int n)
{
	if(n==1)
	return;
	
	swap(a[0],a[n-1]);
	
	heapify(a,n-1,0);
}
void Merge(vector<int> &a,vector<int> &b,int n1,int n2,vector<int> &c)
{
	c.push_back(INT_MAX);
	
	queue<int> q1,q2;
	
	if(n1)
	q1.push(0);
	
	if(n2)
	q2.push(0);
	
	while(q1.size() || q2.size())
	{
		int size1=q1.size();
		while(size1--)
		{
			int i=q1.front();
			q1.pop();
			
			c.push_back(a[i]);
			
			if(i*2+1<n1)
			q1.push(i*2+1);
			
			if(i*2+2<n1)
			q1.push(i*2+2);
		}
		
		int size2=q2.size();
		while(size2--)
		{
			int i=q2.front();
			q2.pop();
			
			c.push_back(b[i]);
			
			if(i*2+1<n2)
			q2.push(i*2+1);
			
			if(i*2+2<n2)
			q2.push(i*2+2);
		}
	}
	
	extract_top(c,n1+n2+1);
	
	c.pop_back();
}
signed main()
{
	vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    
	int n1=a.size();
	int n2=b.size();
	
	vector<int> c;
	
	Merge(a,b,n1,n2,c);
	
	for(auto i:c)
	cout<<i<<" ";
	
	cout<<endl;
	
	return 0;
}
