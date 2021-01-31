#include<bits/stdc++.h>
using namespace std;
int NoofWays(vector<int> &a,int n,int V,int T,int K)
{
	int dp[K+1][V+1];  memset(dp,0,sizeof(dp));
	
	dp[0][0] = 1;
	
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < T ; j++)
		{
			for(int k = min(K , i*T + j + 1) ; k >= 1 ; k--)
			{
				for(int l = 0 ; l <= V ; l++)
				{
					if(dp[k-1][l] && l + a[i] <= V)
					dp[k][l+a[i]]++;
				}
			}
		}
	}
	return dp[K][V];
}
signed main()
{
	vector<int> a = {1, 2, 3, 4};
	int n = a.size();
	
	int V = 9 , T = 3 , K = 4;
	
	cout<< NoofWays(a,n,V,T,K) <<endl;
    
	return 0;
}
