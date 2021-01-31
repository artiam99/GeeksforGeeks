#include<bits/stdc++.h>
using namespace std;
void MaxProfit(vector<int> &a,int n)
{
	int dp[n];
	
	dp[0] = 0;
	
	int prev_diff = INT_MIN;
	
	int ind;
	
	int in[n];
	
	for(int i = 1 ; i < n ; i++)
	{
		if(prev_diff < dp[i-1] - a[i-1])
		{
			prev_diff = dp[i-1] - a[i-1];
			
			ind = i-1;
		}
		
		if(dp[i-1] < prev_diff + a[i])
		{
			dp[i] = prev_diff + a[i];
			
			in[i] = ind;
		}
		else
		dp[i] = dp[i-1];
	}
	
	cout<< "Max Profit : " << dp[n-1] << endl << endl;
	
	stack<pair<int,int>> st;
	
	for(int i = n-1 ; i > 0 ; i--)
	{
		if(dp[i-1] == dp[i])
		continue;
		
		else
		{
			st.push({in[i],i});
			
			i = in[i] + 1;
		}
	}
	
	if(!st.size())
	cout<< "No Profit" ;
	
	while(st.size())
	{
		cout<< "(" << st.top().first << " " << st.top().second << ") ";
		
		st.pop();
	}
	
	cout<< endl << endl << endl;
}
signed main()
{
	vector<int> a = {100, 180, 260, 310, 40, 535, 695};
	int n = a.size();
	
	MaxProfit(a,n);
	
	vector<int> b = {100, 50, 30, 20};
	int m = b.size();
	
	MaxProfit(b,m);
	
	return 0;
}
