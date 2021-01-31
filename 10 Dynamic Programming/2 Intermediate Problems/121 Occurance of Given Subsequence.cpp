#include<bits/stdc++.h>
using namespace std;
int Occurance(string s1,string s2)
{
	int n1 = s1.length() , n2 = s2.length();
        
    int dp[n1+1][n2+1];
    
    for(int i = 0 ; i <= n1 ; i++)
    for(int j = 0 ; j <= n2 ; j++)
    {
        if(j == 0)  dp[i][j] = 1;
        
        else if(i == 0)  dp[i][j] = 0;
        
        else
        {
            if(s1[i-1] == s2[j-1])
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            
            else
            dp[i][j] = dp[i-1][j] ;
        }
    }
    return dp[n1][n2];
}
signed main()
{
	string s1 = "geeksforgeeks";
	string s2 = "gks";
	
	cout<< Occurance(s1,s2) <<endl;
	
	return 0;
}
