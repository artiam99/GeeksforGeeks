#include<bits/stdc++.h>
using namespace std;
int Rec(string s,int n,int i,int mn,vector<vector<int>> &dp)
{
    if(i == n) return 1;
    
    if(dp[i][mn] != -1) return dp[i][mn];
    
    int ans = 0 , sum = 0;
    
    for(int j = i ; j < n ; j++)
    {
        sum += s[j]-48;
        
        if(sum >= mn)
        ans += Rec(s,n,j+1,sum,dp);
    }
    return dp[i][mn]=ans;
}
int CountGroupings(string s)
{
    int n = s.length();
    
    int sum=0;
    
    for(int i = 0 ; i < n ; i++)
    sum += s[i] - 48;
    
    vector<vector<int>> dp(n , vector<int>(sum + 1 , -1));
    
    return Rec(s,n,0,0,dp);
}
signed main()
{
	string s = "1119";
	
	cout<< CountGroupings(s) <<endl;
    
	return 0;
}
