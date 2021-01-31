#include<bits/stdc++.h>
using namespace std;
struct job
{
	int s,e,p;
};
bool comp(job a,job b)
{
	return a.e < b.e;
}
int binarysearch(vector<job> &a,int n)
{
	int l = 0 , r = n-1;
	
	while(l <= r)
	{
		int m = l + (r - l)/2;
		
		if(a[m].e <= a[n].s)
		{
			if(a[m+1].e <= a[n].s)
			l = m + 1;
			
			else
			return m;
		}
		else
		r = m - 1;
	}
	return -1;
}
void findMaxProfit(vector<job> &a,int n)
{
	int dp[n] , in[n];
	
	sort(a.begin(),a.end(),comp);
	
	for(int i=0;i<n;i++)
	dp[i] = a[i].p, in[i] = -1;
	
	for(int i=1;i<n;i++)
	{
		int l = binarysearch(a,i);
		
		if(l != -1 && dp[i] < dp[l] + a[i].p)
		{
			dp[i] = dp[l] + a[i].p;
			
			in[i] = l;
		}
	}
	
	int ind = max_element(dp,dp+n) - dp;
	
	stack<int> st;
	
	while(ind != -1)
	{
		st.push(ind);
		
		ind = in[ind];
	}
	
	while(st.size())
	{
		ind = st.top();
		
		cout<< "( " << a[ind].s << " , " << a[ind].e << " , " << a[ind].p << " ) ";
		
		st.pop();
	}
}
signed main()
{
    vector<job> a = { {3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200} }; 
    int n = a.size();
    
    findMaxProfit(a , n); 
  
    return 0; 
}
