#include<bits/stdc++.h>
using namespace std;
int LCS(string s1,int n1,string s2,int n2)
{
	int mx=0;
    vector<vector<int>> dp(2,vector<int>(n2));
    
	for(int i=0;i<n1;i++)
    for(int j=0;j<n2;j++)
    {
        if(s1[i]==s2[j])
        dp[i%2][j]=((i==0 || j==0)? 0 : dp[1-i%2][j-1]) + 1 , mx = max(mx , dp[i%2][j]);
        
		else
        dp[i%2][j]=0;
    }
    return mx;
}
signed main()
{
	string s1 = "GeeksforGeeks";
	string s2 = "GeeksQuiz";
    
    cout<< LCS(s1,s1.length(),s2,s2.length()) <<endl;
    
	return 0;
}
