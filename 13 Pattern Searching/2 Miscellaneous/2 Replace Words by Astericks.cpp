#include<bits/stdc++.h>
using namespace std;
void ConstructLPS(string &pat,int p,int lps[])
{
	lps[0] = 0;
	
	int i = 1 , j = 0;
	
	while(i < p)
	{
		if(pat[i] == pat[j])  lps[i++] = ++j;
		
		else
		{
			if(j == 0)  lps[i++] = 0;
			
			else  j = lps[j-1];
		}
	}
}
void Replace(string &s,int n,string &pat,int p)
{
	int lps[p];
	
	ConstructLPS(pat,p,lps);
	
	int last = -1;
	
	int i = 0 , j = 0;
	
	while(i < n)
	{
		if(j < p && s[i] == pat[j])  i++ , j++;
		
		else
		{
			if(j == 0)  i++;
			
			else  j = lps[j-1];
		}
		
		if(j == p)
		{
			for(int k = max(last+1 , i-p) ; k < i ; k++)
			s[k] = '*';
			
			last = i-1;
		}
	}
	cout<< s << endl;
}
signed main()
{
	string s = "aaabaaaab";
	int n = s.length();
	
	string pat= "aab";
	int p = pat.length();
	
	Replace(s,n,pat,p);
	
	return 0;
}
