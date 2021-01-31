#include<bits/stdc++.h>
using namespace std;
bool perfect(int n)
{
	for(int i=1;i*i<=n;i++)
	if(i*i==n)
	return true;
	
	return false;
}
bool WeiredGame(int n)
{
	bool dp[n+1];
	
	dp[0]=false;
	
	bool p[n+1];
	
	for(int i=1;i<=n;i++)
	{
		dp[i]=false;
	
		p[i]=perfect(i);
	
		for(int j=1;j<=i;j++)
		if(p[j] && i-j>=0 && !dp[i-j])
		{
			dp[i]=true;
	
			break;
		}
	}
	
	return dp[n];
}
signed main()
{
	int n = 5;
	
	if(WeiredGame(n))
    cout<< "A wins" <<endl;
    
	else
    cout<< "B wins" <<endl;
    
	return 0;
}
