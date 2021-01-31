#include<bits/stdc++.h>
using namespace std;
void Rec(int ind,string &s,int n,int a[])
{
    if(ind == n)
    {
        cout<< s << " ";
        return;
    }
    for(int i = 0 ; i < 26 ; i++)
    if(a[i])
    {
        a[i]--;
        s[ind] = 'A' + i;
        Rec(ind+1,s,n,a);
        a[i]++;
    }
}
void AllPermutation(string s,int n)
{
	int a[26];  memset(a,0,sizeof(a));
	    
    for(int i = 0 ; i < n ; i++)
    a[s[i]-'A']++;
    
    Rec(0,s,n,a);
}
signed main()
{
	string s = "ABC";
	int n = s.length();
	
	AllPermutation(s,n);
	
	return 0;
}
