#include<bits/stdc++.h>
using namespace std;
int ComputeTF(string &pat,int p,int TF[][26])
{
        int lps = 0;
    
    for(int i = 0 ; i <= p ; i++)
    {
        for(int j = 0 ; j < 26 ; j++)
        {
            if(i == 0)
            TF[i][j] = 0;
            
            else
            TF[i][j] = TF[lps][j];
        }
        
        if(i < p)
        TF[i][pat[i]-'A'] = i + 1;
        
        if(i > 0 && i < p)
        lps = TF[lps][pat[i]-'A'];
    }
}
void Search(string &s,int n,string &pat,int p)
{
    int TF[p+1][26];
    
    ComputeTF(pat,p,TF);
    
    int Shift[n];
    
    int state = 0;
    
    bool flag = true;
    
    for(int i = 0 ; i < n ; i++)
    {
        state = TF[state][s[i]-'A'];
        
        if(state == p)
        {
            cout<< i-p+1 << " ";
            
            flag = false;
        }
    }
    
    if(flag)
    cout<< -1;
    
    cout<< endl;
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
