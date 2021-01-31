#include<bits/stdc++.h>
using namespace std;
int NoofSubstring(string s)
{
	int n = s.length();
    
    long long ans = 0;
    
    long long dp[n][3]; //  dp[i][x] stores Number of Substrings ends at i that has digit Sum Mod 3 equal to x
    
    dp[0][0] = (s[0]%3 == 0);
	dp[0][1] = (s[0]%3 == 1);
	dp[0][2] = (s[0]%3 == 2);
    
    for(int i = 1 ; i < n ; i++)
    {
        int m = s[i]%3;
        
        dp[i][m] = dp[i-1][0];
		dp[i][((m+1)%3)] = dp[i-1][1];
		dp[i][((m+2)%3)] = dp[i-1][2];
        
        dp[i][m]++;
    }
    
	for(int i = 0 ; i < n ; i++)
	{
	    if(i >= 2)
	    {
	        
	        if( ((s[i]-48) + (s[i-1]-48)*10 + (s[i-2]-48)*100) % 8 == 0) // if Number, formed by Last 3 digits ,
			{                                                           //is divisible by 8 the whole Number is Divisible by 8
	            int m = ((s[i]-48) + (s[i-1]-48) + (s[i-2]-48))%3;
	            
	            if(i > 2)
	            {
	                if(m==0)
	                ans += dp[i-3][1] + dp[i-3][2];
	                
	                else if(m==1)
	                ans += dp[i-3][0] + dp[i-3][1];
	                
	                else
	                ans += dp[i-3][0] + dp[i-3][2];
	            }
	        }
	        int x= (s[i]-48) ; int y = (s[i-1]-48) * 10 + x ; int z = (s[i-2]-48) * 100 + y;
            
             ans += (x%8 == 0 && x%3 != 0)+(y%8 == 0 && y%3 != 0)+(z%8 == 0 && z%3 != 0);
	    }
	    else
	    {
	        if(i == 0)
	        ans += (s[0]%8 == 0 && s[i]%3 !=0);
	        
	        if(i == 1)
	        {
	            int x = (s[0]-48) ; int y = (s[1]-48) ; int z = (x*10 + y);
            
                ans += (y%8 == 0 && y%3 != 0)+(z%8 == 0 && z%3 != 0);
	        }
	    }
	}
	
	return ans;
}
signed main()
{
	string s = "8888888";
	
	cout<< NoofSubstring(s) <<endl;
	
	return 0;
}
