#include<bits/stdc++.h>
using namespace std;
int Count(string &s,int i,int j,vector<vector<int>> &dp)
{
    if(i>j)  return 0;
    
    if(i==j)  return 1;
    
    if(dp[i][j] != -1)  return dp[i][j];
    
    if(s[i]==s[j])  return dp[i][j] = Count(s,i+1,j,dp) + Count(s,i,j-1,dp) + 1; // Case 1 [1 + Count(s,i+1,j-1,dp)] + Case 2 [ Count(s,i+1,j,dp) + Count(s,i,j-1,dp) - Count(s,i+1,j-1,dp) ]
                                                                                //            Include both i and j               Exclude i            Exclude j          Common in Both
    
	return dp[i][j] = Count(s,i+1,j,dp) + Count(s,i,j-1,dp) - Count(s,i+1,j-1,dp);  // Case 2 [ Count(s,i+1,j,dp) + Count(s,i,j-1,dp) - Count(s,i+1,j-1,dp) ]
}                                                                                  //              Exclude i            Exclude j          Common in Both
int CountPSS(string s,int n)
{
	vector<vector<int>> dp(n,vector<int>(n,-1));
	
	return Count(s,0,n-1,dp);
}
signed main()
{
	string s = "GEEKSFORGEEKS";
	int n = s.length();
    
    cout<< CountPSS(s,n) <<endl;
    
	return 0;
}
