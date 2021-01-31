#include<bits/stdc++.h>
using namespace std;
int PalindromPartition(string &s,int n)
{
	bool ispal[n][n];
        
    for(int i = 0 ; i < n ; i++)
    {
        int l = i , r = i;  bool flag = true;
        
        while(l >= 0 && r < n)
        {
            if(s[l] != s[r])  flag = 0;
            
            ispal[l--][r++] = flag;
        }
        
		l = i ; r = i+1;  flag = true;
        
        while(l >= 0 && r < n)
        {
            if(s[l] != s[r])  flag = 0;
            
            ispal[l--][r++] = flag;
        }
    }
    
    int dp[n];
    
    for(int i = 0 ; i < n ; i++)
    {
        dp[i] = INT_MAX;
        
        for(int j = i ; j >= 0 ; j--)
        if( ispal[j][i] )
        dp[i] = min(dp[i] , ((j == 0) ? 0 : dp[j-1] + 1 ));
    }
    return dp[n-1];
}
signed main()
{
	string s = "aaabba";
	int n = s.length();
	
	cout<< PalindromPartition(s,n) <<endl;
    
	return 0;
}
