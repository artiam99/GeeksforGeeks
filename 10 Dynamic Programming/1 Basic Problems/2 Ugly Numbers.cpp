#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int Ugly(int n)
{
	vector<int> dp(1,1);
	
	int i2=0,i3=0,i5=0;
	
	while(dp.size()<n)
	{
		int mn = min( min(dp[i2]*2 , dp[i3]*3) , dp[i5]*5);
		
		if(dp[dp.size()-1]!=mn)
		dp.push_back(mn);
		
		(mn == dp[i2]*2) ? i2++ : (mn == dp[i3]*3) ? i3++ : i5++;
	}
	return dp[n-1];
}
signed main()
{
    int n=10;
    
    cout<< Ugly(n) <<endl;
    
	return 0;
}
