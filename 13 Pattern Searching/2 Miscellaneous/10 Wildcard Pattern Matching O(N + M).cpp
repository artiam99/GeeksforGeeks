#include<bits/stdc++.h>
using namespace std;
int WildCard(string s,int n,string pat,int p)
{    
    int i = 0 , j = 0 , iStar = -1 , jStar = -1;

    while (i < n)
    {
        if(s[i] == pat[j] || pat[j] == '?')  ++i , ++j;
        
        else if(pat[j] == '*')  iStar = i , jStar = j++;
        
        else if(iStar != -1)  i = ++iStar , j = jStar + 1;
        
        else  return false;
    }
    
    while (pat[j] == '*')  ++j;
    
    return (j == p);
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
