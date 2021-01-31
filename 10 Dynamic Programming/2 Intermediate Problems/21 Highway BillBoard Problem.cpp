#include<bits/stdc++.h>
using namespace std;
int HighwayBillBoard(int m,int x[],int rev[],int n,int t)
{
	int dp[m+1];
	memset(dp,0,sizeof(dp));
	
	int bb = 0;
	for(int i=1;i<=m;i++)
	{
		if(bb < n)
		{
			if(x[bb] != i)
			dp[i] = dp[i-1];
			
			else
			{
				dp[i] = max(dp[i-1] , ((i > t) ? dp[i-t-1] : 0 ) + rev[bb]);
			
				bb++;
			}
		}
		else
		dp[i] = dp[i-1];
	}
	return dp[m];
}
signed main()
{
	int m = 20;
 
    int x[] = {6, 7, 12, 13, 14};
 
    int revenue[] = {5, 6, 5, 3, 1};
 
    int n = sizeof(x)/sizeof(x[0]);
 
    int t = 5;

    cout << HighwayBillBoard(m, x, revenue, n, t) << endl;
    
	return 0;
}
