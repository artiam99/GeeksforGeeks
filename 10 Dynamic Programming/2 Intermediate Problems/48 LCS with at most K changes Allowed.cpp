#include<bits/stdc++.h>
using namespace std;
int LCSK(vector<int> &a1,int n1,vector<int> &a2,int n2,int k)
{
	int dp[k+1][n1+1][n2+1];
	
	for(int i=0;i<=k;i++)
	for(int j=0;j<=n1;j++)
	for(int l=0;l<=n2;l++)
	{	
		if(j==0 || l==0)  dp[i][j][l] = 0;
		
		else if(i==0)  dp[i][j][l] = INT_MIN;
		
		else if(a1[j-1] == a2[l-1])  dp[i][j][l] = max(dp[i][j-1][l-1] + 1 , max(dp[i][j-1][l] , dp[i][j][l-1]));
		
		else dp[i][j][l] = max(dp[i-1][j-1][l-1] + 1 , max(dp[i][j-1][l] , dp[i][j][l-1]));
	}
	return dp[k][n1][n2];
}
signed main()
{
	vector<int> a1 = {1, 2, 3, 4, 5 };
	int n1 = a1.size();
	
	vector<int> a2 = {5, 3, 1, 4, 2};
	int n2 = a2.size();
	
	int k = 1;
    
    cout<< LCSK(a1,n1,a2,n2,k) <<endl;
    
	return 0;
}
