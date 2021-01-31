#include<bits/stdc++.h>
using namespace std;
void MinCost(vector<int> &a,int n,int M,int target)
{
	int dp[n][M+1]; // dp[i][j] stores Min Cost to Make a[i] , j
	
	int val[n][M+1];
	
	int mn = INT_MAX , mni;
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j <= M ; j++)
		{
			if(i == 0)  dp[i][j] = abs(a[i] - j);
			
			else
			{
				dp[i][j] = INT_MAX;
				
				for(int k = max(0 , j-target) ; k <= min(M , j+target) ; k++)
				{
					if(dp[i][j] >= dp[i-1][k] + abs(a[i] - j))
					{
						dp[i][j] = dp[i-1][k] + abs(a[i] - j);
						
						val[i][j] = k;
					}
				}
			}
			if(i == n-1 && mn >= dp[i][j])
			{
				mn = dp[i][j];
				
				mni = j;
			}
		}
	}
	
	cout<< "Minimum Cost : " << mn << endl << endl;
	
	
	cout<< "New Array : " ;  // Multiple New Arrays could be there so It's not important to print the new array
	
	stack<int> st;
	
	st.push(mni);
	
	for(int i = n-1 ; i > 0 ; i--)
	st.push(val[i][st.top()]);
	
	
	while(st.size())
	{
		cout<< st.top() <<" ";
		
		st.pop();
	}
	cout<<endl;
}
signed main()
{
	int M = 100;
	
	vector<int> a = {1, 3, 0 ,3}; // 0 <= a[i] <= M
	int n = a.size();
	
	int target = 1;
	
	MinCost(a,n,M,target);
	
	return 0;
}
