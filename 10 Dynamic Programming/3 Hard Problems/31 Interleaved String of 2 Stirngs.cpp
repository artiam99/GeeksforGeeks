#include<bits/stdc++.h>
using namespace std;
bool Check(string a,string b,string c) 
{
    int n1 = a.length() , n2 = b.length() , n3 = c.length();
    
    if(n3 != n1 + n2)  return false;
    
    int dp[n1+1][n2+1];
    
    for(int i = 0 ; i <= n1 ; i++)
    for(int j = 0 ; j <= n2 ; j++)
    {
        if(i == 0 && j == 0)  dp[i][j] = true;
        
        else if(i == 0)
        {
            if(c[i+j-1] != b[j-1])  dp[i][j] = false;
            
            else  dp[i][j] = dp[i][j-1];
        }
            
        else if(j == 0)
        {
            if(c[i+j-1] != a[i-1])  dp[i][j] = false;
            
            else  dp[i][j] = dp[i-1][j];
        }
        
        else
        {
            dp[i][j] = false;
            
            if(c[i+j-1] == a[i-1] && dp[i-1][j])  dp[i][j] = true;
            
            if(c[i+j-1] == b[j-1] && dp[i][j-1])  dp[i][j] = true;
        }
    }
    return dp[n1][n2];
}
signed main()
{
	string A = "XXY" , B = "XXZ" , C = "XXXYXZ";
	
	if(Check(A,B,C))
	cout<< "YES" <<endl;
	
	else
	cout<< "NO" <<endl;
	
	return 0;
}
