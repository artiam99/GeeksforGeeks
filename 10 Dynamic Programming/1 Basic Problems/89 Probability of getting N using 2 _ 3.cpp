#include<bits/stdc++.h>
using namespace std;
double FindProb(int N,double P)
{
	double dp[N+1];
	
	dp[0]=1;
	dp[1]=0;
	dp[2]=P;
	dp[3]=1-P;
	
	for(int i=4;i<=N;i++)
	dp[i] = P*dp[i-2] + (1-P)*dp[i-3];
	
	return dp[N];
}
signed main()
{
	int N = 5;
	double P = 0.2;
	
	cout<< (double)FindProb(N,P) <<endl;
	
	return 0;
}
