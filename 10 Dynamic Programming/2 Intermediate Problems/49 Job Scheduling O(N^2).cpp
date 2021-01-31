#include<bits/stdc++.h>
using namespace std;
struct job
{
	int s,e,p;
};
bool comp(job a,job b)
{
	return a.s < b.s;
}
void findMaxProfit(vector<job> &a,int n)
{
	int dp[n] , in[n];
	
	sort(a.begin(),a.end(),comp);
	
	for(int i=0;i<n;i++)
	dp[i] = a[i].p, in[i] = -1;
	
	for(int i=1;i<n;i++)
	for(int j=0;j<i;j++)
	if(a[j].e <= a[i].s && dp[i] < dp[j] + a[i].p)
	dp[i] = dp[j] + a[i].p , in[i] = j;
	
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
