#include<bits/stdc++.h>
using namespace std;
int MaxTrailingZero(vector<int> &a,int n,int k)
{
	vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(k+1));
	
	int p2 , p5 , p2_ , p5_ ;
	
	for(int i = 1 ; i <= n ; i++)
	{
		int pw2 = 0 , pw5 = 0;
		
		while(a[i-1] % 2 == 0)
		{
			pw2++;
			
			a[i-1] /= 2;
		}
		
		while(a[i-1] % 5 == 0)
		{
			pw5++;
			
			a[i-1] /= 5;
		}
		
		for(int j = 1 ; j <= min(i , k) ; j++)
		{
			p2 = dp[i-1][j-1].first + pw2;
			p5 = dp[i-1][j-1].second + pw5;
			
			p2_ = dp[i-1][j].first;
			p5_ = dp[i-1][j].second;
			
			int x = min(p2 , p5);
			
			int y = min(p2_ , p5_);
			
			if(x >= y)
			dp[i][j] = {p2 , p5};
			
			else
			dp[i][j] = {p2_ , p5_};
		}
	}
	
	return min(dp[n][k].first , dp[n][k].second);
}
signed main()
{
	vector<int> a = {15, 16, 3, 25, 9};
	int n = a.size();
	
	int k = 3;
	
	cout<< MaxTrailingZero(a,n,k) <<endl;
	
	return 0;
}
