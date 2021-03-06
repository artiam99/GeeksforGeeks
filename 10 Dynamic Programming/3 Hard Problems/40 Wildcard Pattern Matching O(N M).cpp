#include<bits/stdc++.h>
using namespace std;
bool WildCard(string s,int n,string pat,int p)
{    
    bool dp[2][n+1];

    bool flag = true;

    for(int i = 0 ; i <= p ; i++)
    {
        if(i > 0 && pat[i-1] != '*')  flag = false;

        for(int j = 0 ; j <= n ; j++)
        {
            if(i == 0 && j == 0)  dp[i%2][j] = 1;

            else if(i == 0)  dp[i%2][j] = 0;

            else if(j == 0)
            dp[i%2][j] = ((pat[i-1] == '*') ? flag : false);

            else
            {
                if(pat[i-1] != '*')
                {
                    if(pat[i-1] == '?' || pat[i-1] == s[j-1])
                    dp[i%2][j] = dp[1-i%2][j-1];

                    else dp[i%2][j] = false;
                }
                else
                dp[i%2][j] = (dp[1-i%2][j] | dp[i%2][j-1]);
            }
        }
    }

    return dp[p%2][n];
}
signed main()
{
	string s = "baaabab";
	int n = s.length();
	
	string pat = "ba*a?";
	int p = pat.length();
	
	if(WildCard(s,n,pat,p))  cout<< "Matches" << endl;
	
	else  cout<< "Not Matches" << endl;
	
	return 0;
}
