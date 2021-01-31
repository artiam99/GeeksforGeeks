#include<bits/stdc++.h>
using namespace std;
void ConstructLPS(string pat,int p,int lps[])
{
	lps[0] = 0;
	
	int i = 1 , len = 0;
	
	while(i < p)
	{
		if(pat[i] == pat[len])
		lps[i++] = ++len;
		
		else
		{
			if(len == 0)  lps[i++] = 0;
			
			else  len = lps[len-1];
		}
	}
}
void Search(string &s,int n,string &pat,int p)
{
	int lps[p];
	
	ConstructLPS(pat,p,lps);
	
	int i = 0 , j = 0;
	
	bool flag = true;
	
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
			if(flag)
			cout << "Pattern Found at : ";
			
			cout<< i - p << " ";
			
			flag = false; 
		}
	}
	
	if(flag)
	cout<< "Pattern Not Found" << endl;
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
