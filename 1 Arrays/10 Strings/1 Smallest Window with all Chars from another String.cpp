#include<bits/stdc++.h>
using namespace std;

string Smallest_Window(string &S , string &P)
{
	int pat[26];  memset(pat,0,sizeof(pat));
    
    for(int i = 0 ; i < P.length() ; i++)
    pat[P[i]-'a']++;
    
    int alpha[26];  memset(alpha,0,sizeof(alpha));
    
    int i = 0 , j = 0;
    
    string ans; 
    
    int mn = INT_MAX;
    
    while(i < S.length())
    {
        alpha[S[i]-'a']++;
        
        bool flag = true;
        
        for(int k = 0 ; k < 26 ; k++)
        if(pat[k])
        {
            if(alpha[k] < pat[k])
            {
                flag = false;
                
                break;
            }
        }
        
        if(flag)
        {
            while(j <= i && (!pat[S[j] - 'a'] || (pat[S[j] - 'a'] && alpha[S[j]-'a'] > pat[S[j]-'a'])))
            alpha[S[j] - 'a']-- , j++;
            
            if(mn > i - j + 1)
            {
                mn = i - j + 1;
                
                ans = S.substr(j , i - j + 1);
            }
            
            alpha[S[j] - 'a']--;
            
            j++;
        }
        
        i++;
    }
    
    if(ans.length() == 0)
    ans = "-1";
    
    return ans;
}

signed main()
{
	string S = "timetopractice";
	
	string P = "toc";
	
	cout << Smallest_Window(S , P) << endl;
	
	return 0;
}
