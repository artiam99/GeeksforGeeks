#include<bits/stdc++.h>
using namespace std;
void Search(string &s,int n,string &pat,int p)
{
    int badchar[26];  memset(badchar,-1,sizeof(badchar));
    
    for(int i = 0 ; i < p ; i++)
    badchar[pat[i]-'A'] = i;
    
    int i = 0;
    
    while(i <= n-p)
    {
    	int j = p-1;
    	
    	while(j >= 0 && s[i+j] == pat[j])
    	j--;
    	
    	if(j == -1)
    	{
    		cout<< i << " ";
    		
    		i += ((i + p < n) ? p - badchar[s[i+p]-'A'] : 1);
		}
		else
		{
			i += max(1 , j - badchar[s[i+j]-'A']);
		}
	}
}
signed main()
{
	string s = "AABAACAADAABAABA";
	int n = s.length();
	
	string pat = "AABA";
	int p = pat.length();
	
	Search(s,n,pat,p);
	
	return 0;
}
