#include<bits/stdc++.h>
using namespace std;
int MinStep(int N,int I,int D,int C)
{
	vector<int> dp(N+1);
	
	for(int i=1;i<=N;i++)
	{
		if(i%2==0)  dp[i] = min(dp[i-1] + I , dp[i/2] + C);
		
		else  dp[i] = min(dp[i-1] + I , dp[(i+1)/2] + C + D);
	}
	return dp[N];
}
signed main()
{
	int N = 9 , I = 1 , D = 2 , C = 1;
	
	cout<< MinStep(N,I,D,C) <<endl;
    
	return 0;
}
