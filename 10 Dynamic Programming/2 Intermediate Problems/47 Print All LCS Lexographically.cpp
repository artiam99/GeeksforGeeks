#include<bits/stdc++.h>
using namespace std;
int LCS(string &s,int n,string &t,int m,int i,int j,vector<vector<int>> &dp)
{
	if(i==n || j==m)  return 0;
	
	if(dp[i][j] != -1)  return dp[i][j];
	
	if(s[i]==t[j])  return  dp[i][j] = 1 + LCS(s,n,t,m,i+1,j+1,dp);
	
	return  dp[i][j] = max(LCS(s,n,t,m,i+1,j,dp) , LCS(s,n,t,m,i,j+1,dp));
}
void PrintAll(string &s,int n,string &t,int m,vector<vector<int>> &dp,int lcslen,string s1,int ind1,int ind2,int currlen,vector<string> &a)
{
	if(currlen == lcslen)
	{
		a.push_back(s1);
		
		return;
	}
	
	if(ind1==n || ind2==m)  return;
	
	for(char c = 'a'; c <= 'z' ; c++)
	{
		bool flag = false;
		
		for(int i=ind1;i<n;i++)
		{
			if(s[i] == c)
			{
				for(int j=ind2;j<m;j++)
				{
					if(t[j] == c && dp[i][j] == lcslen - currlen)
					{
						string s2 = s1;
						s2 += c;
						
						PrintAll(s,n,t,m,dp,lcslen,s2,i+1,j+1,currlen+1,a);
						
						flag = true;
						break;
					}
				}
			}
			
			if(flag)
			break;
		}
	}
}
void PrintLCS(string s,int n,string t,int m)
{
	vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	
	int lcslen = LCS(s,n,t,m,0,0,dp);
	
	vector<string> a;
	
	string s1;
	
	PrintAll(s,n,t,m,dp,lcslen,s1,0,0,0,a);
	
	for(auto i:a)
	cout<< i <<endl;
}
signed main()
{
	string s = "abcabcaa";
	string t = "acbacba";
	
	int n = s.length();
	int m = t.length();
    
    PrintLCS(s,n,t,m);
    
	return 0;
}
