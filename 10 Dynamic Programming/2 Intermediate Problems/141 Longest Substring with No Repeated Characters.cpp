#include<bits/stdc++.h>
using namespace std;
int LongestSubString(string &s)
{
	int n = s.length();
	    
    bool alpha[26];  memset(alpha,false,sizeof(alpha));
    
    int mx = 1;
    
    int l = 0; alpha[s[0]-'a'] = true;
    
    int curr = 1;
    
    for(int i = 1 ; i < n ; i++)
    {
        if(!alpha[s[i]-'a'])
        {
            alpha[s[i]-'a'] = true;
            
            curr++;
            
            mx = max(mx , curr);
        }
        else
        {
            while(s[l] != s[i])
            {
                alpha[s[l++]-'a'] = false;
                
                curr--;
            }
            l++;
        }
    }
    return mx;
}
signed main()
{
	string s = "geeksforgeeks";
	
	cout<< LongestSubString(s) <<endl;
	
	return 0;
}
