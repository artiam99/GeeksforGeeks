#include<bits/stdc++.h>
using namespace std;
int LongestPrefix(string &pat,int p,int state,char ch)
{
    for(int i = state ; i >= 0 ; i--)
    {
        int j = i;
        
        for(int k = state ; k >= 0 ; k--)
        {
            if(pat[j] == ((k == state) ? ch : pat[k]))
            j--;
            
            else break;
            
            if(j == -1)  return i+1;
        }
    }
    return 0;
}
int ComputeTF(string &pat,int p,int TF[][26])
{
    for(int i = 0 ; i <= p ; i++)
    for(int j = 0 ; j < 26 ; j++)
    TF[i][j] = LongestPrefix(pat , p , i , j+'A');
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
