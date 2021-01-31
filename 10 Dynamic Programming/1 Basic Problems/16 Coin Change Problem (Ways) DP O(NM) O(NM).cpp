#include<bits/stdc++.h>
using namespace std;
int CountWay(vector<int> &a,int m,int n)
{
	int dp[n+1][m];
	
	for(int i=0;i<m;i++)
	dp[0][i]=1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x = ((i-a[j] >= 0) ? dp[i-a[j]][j] : 0);
			
			int y = ((j>0) ? dp[i][j-1] : 0);
			
			dp[i][j] = x + y;
		}
	}
	return dp[n][m-1];
}
signed main()
{
    vector<int> a={1,2,3};
    int m=a.size();
    
    int n=4;
    
    cout<< CountWay(a,m,n) <<endl;
    
	return 0;
}
