#include<bits/stdc++.h>
using namespace std;
bool Check(vector<int> &a,int n,int x)
{
	int sum = accumulate(a.begin(),a.end(),0);
	
	if(sum > x * 2)  return false;
	
	if(sum <= x)  return true;
	
	bool dp[2][x+1];
	
	for(int i = 0 ; i <= n ; i++)
	for(int j = 0 ; j <= x ; j++)
	{
		if(j == 0)  dp[i%2][j] = 1;
		
		else if(i == 0)  dp[i%2][j] = 0;
		
		else
		{
			dp[i%2][j] = dp[1-i%2][j];
			
			if(j >= a[i-1])  dp[i%2][j] = (dp[i%2][j] | dp[i%2][j-a[i-1]]);
		}
		
		if(j >= sum - x && dp[i%2][j])  return true;
	}
	return false;
}
signed main()
{
	int x = 4;
	
	vector<int> a = {2, 4, 2};
	int n = a.size();
    
    if(Check(a,n,x))
    cout<< "YES" <<endl;
    
    else
    cout<< "NO" <<endl;
    
	return 0;
}
