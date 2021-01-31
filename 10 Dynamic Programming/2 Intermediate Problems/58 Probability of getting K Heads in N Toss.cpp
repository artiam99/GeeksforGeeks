#include<bits/stdc++.h>
using namespace std;
double Prob(int n,int k)
{
	double dp[n+1];
	
	dp[0] = 1.0;
	
	for(int i=1;i<=n;i++)
	dp[i] = log2(i) + dp[i-1]; // We are storing Factorial in Log Value to avoid overflow.
	
	double ans = 0.0 ;
	
	for(int i=k;i<=n;i++)  // Summatin of ...n C k (p)^k (1-p)^n-k
	{
		double res = dp[n] - dp[i] - dp[n-i] - n;
		
		ans += pow(2.0 , res);
	}
	return ans;
}
signed main()
{
	int n = 1000 , k = 500;
	
	cout<< (double)Prob(n,k) <<endl;
    
	return 0;
}
