#include<bits/stdc++.h>
using namespace std;
int NonDecreasingNumbers(int n)
{
	int dp[n+1][9]; // Ans is N + 9 C N .... NonDecrease Numbers with digits less than or equal to N .... N + 8 C N for Only equal to N
	
	for(int i = 0 ; i <= n ; i++)
	for(int j = 9 ; j >= 0 ; j--)
	{
		if(i==0 || j==9) dp[i][j] = 1;
		
		else dp[i][j] = dp[i-1][j] + dp[i][j+1];
	}
	return dp[n][0];
}
signed main()
{
	cout<< NonDecreasingNumbers(1) << endl;
	
	cout<< NonDecreasingNumbers(2) << endl;
	
	cout<< NonDecreasingNumbers(3) << endl;
	
	return 0;
}
