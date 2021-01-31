#include<bits/stdc++.h>
using namespace std;
int CountISK(vector<int> &a,int n,int k)
{
	int dp[k][n];
	
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0)
			dp[i][j] = 1;
			
			
			else
			{
				dp[i][j] = 0;
				
				for(int l=i-1;l<j;l++)
				if(a[l] < a[j])
				dp[i][j] += dp[i-1][l];
			}
		}
	}
	
	return accumulate(dp[k-1] , dp[k-1] + n , 0);
}
signed main()
{
	vector<int> a = { 12, 8, 11, 13, 10, 15, 14, 16, 20 };
    int n = a.size();
    int k = 4;
    
    cout<< CountISK(a,n,k) <<endl;
  
    return 0;
}
