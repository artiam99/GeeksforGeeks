#include<bits/stdc++.h>
using namespace std;
int Rec(int i,int n,int odd,int even,vector<vector<int>> &dp)
{
	if(i == n)  return ( even - odd == 1);
	
	if(dp[i][even - odd + 9*( n/2 + 1)] != -1)  return dp[i][even - odd + 9*( n/2 + 1)];
	
	int ans = 0;
	
	if(i!=0)  ans += Rec(i+1 , n , odd , even , dp);
	
	for(int j=1;j<=9;j++)
	{
		if(i&1)	 ans += Rec(i + 1 , n , odd + j , even , dp);
		
		else  ans += Rec(i + 1 , n , odd , even + j , dp);
	}
	
	return dp[i][even - odd + 9*( n/2 + 1)] = ans;
}
int CountNumbers(int n)
{
	vector<vector<int>> dp(n , vector<int>( 2 * (9 * (n/2 + 1)) , -1)); // Range of Difference of Even - odd  is [ - 9 * ( n/2 + 1) , 9 * ( n/2 )]

	return Rec(0 , n , 0 , 0 , dp);
}
signed main()
{
	int n = 3;
	
	cout<< CountNumbers(n) <<endl;
    
	return 0;
}
