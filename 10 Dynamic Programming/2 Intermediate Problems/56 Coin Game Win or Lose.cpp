#include<bits/stdc++.h>
using namespace std;
bool AorB(int n,int x,int y)
{
	bool dp[n+1];
	
	dp[0] = false;
	dp[1] = true;
	
	for(int i = 2 ; i <= n; i++)
	{
		if( (i-1 >= 0 && !dp[i-1]) || (i-x >= 0 && !dp[i-x]) || (i-y >= 0 && !dp[i-y]))  dp[i] = true;
		
		else  dp[i] = false;
	}
	return dp[n];
}
signed main()
{
	int n = 5 , x = 3 , y = 4; 
    
    if(AorB(n,x,y))
    cout<< "A wins" <<endl;
    
    else
    cout<< "B wins" <<endl;
    
	return 0;
}
