#include<bits/stdc++.h>
using namespace std;
void PalSstrQueries(string s,int n,vector<pair<int,int>> &Q,int q)
{
   bool dp[2][n];
	    
    int dp2[n][n];
    
    int cnt=0;
    
    for(int i=n-1;i>=0;i--)
    for(int j=0;j<n;j++)
    {
        if(j<i)
        {
            dp2[i][j] = 0;
            
            dp[i%2][j]=false;
            
            continue;
        }
        
        if(i==j)
        {
            dp[i%2][j] = true ;
            
            dp2[i][j]=1;
        }
        
        else if(s[i]==s[j] && (i+1 > j-1 || dp[1-i%2][j-1]))
        {
            dp[i%2][j] = true ;
            
            dp2[i][j] = 1 + (dp2[i+1][j] + dp2[i][j-1] - dp2[i+1][j-1]);
        }
        
        else
        {
            dp[i%2][j]=false;
            
            dp2[i][j] = (dp2[i+1][j] + dp2[i][j-1] - dp2[i+1][j-1]);
        }
    }
    
    for(int i=0;i<q;i++)
    {
    	int l = Q[i].first;
    	int r = Q[i].second;
    	
    	if(l>r) swap(l,r);
    	
    	cout<< dp2[l][r] <<endl;
	}
}

signed main()
{
	string s = "aaaabbaa";
	int n = s.length();
    
    vector<pair<int,int>> Q = {{1,4} , {3,5}};
	int q = Q.size(); 
    
    PalSstrQueries(s,n,Q,q);
    
	return 0;
}
