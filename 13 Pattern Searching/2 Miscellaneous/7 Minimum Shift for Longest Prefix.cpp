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
void Min_Shift(string &s,int n,string &pat,int p)
{
	int lps[p];
	
	ConstructLPS(pat,p,lps);
	
	int i = 0 , j = 0 , mx = 0 , mxi = -1;
	
	while(i < n+p-1)
	{
		if(s[i%n] == pat[j])
		{
			i++; j++;
			
			if(mx < j)
			{
				mx = j;
				
				mxi = (i-j) % n;
			}
		}
		
		else
		{
			if(j == 0)  i++;
			
			else  j = lps[j-1];
		}
	}
	cout<< "Shift : " << mxi << endl << endl;
	
	cout<< "Longest Prefix : "<< pat.substr(0,mx) << endl;
}
signed main()
{
	string s = "ticecoderprac";
	int n = s.length();
	
	string pat= "practicegeeks";
	int p = pat.length();
	
	Min_Shift(s,n,pat,p);
	
	return 0;
}
