#include<bits/stdc++.h>
using namespace std;
int MinAbsDiff(vector<int> &a,int n)
{
	int sum = 0;
    for(int i = 0 ; i < n ; i++)
    sum += a[i];
    
    int half = sum/2;
    
    bool dp[2][sum+1];
    
    for(int i = 0 ; i <= n ; i++)
    for(int j = 0 ; j <= half ; j++)
    {
        if(i == 0)  dp[i%2][j] = (j==0);
        
        else dp[i%2][j] = (dp[1-i%2][j] | ((j >= a[i-1]) ? dp[1-i%2][j-a[i-1]] : 0));
    }
    
    int i = half;
    
	for(; i >= 0 ; i--)
    if(dp[n%2][i])
    break;
    
    return abs(sum - 2 * i);
}
signed main()
{
	vector<int> a = {5, 2, 3, 1, 4};
	int n = a.size();
	
	cout<< MinAbsDiff(a,n) <<endl;
	
	return 0;
}
