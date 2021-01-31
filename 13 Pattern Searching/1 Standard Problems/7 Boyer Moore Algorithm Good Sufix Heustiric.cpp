#include<bits/stdc++.h>
using namespace std;
void Preprocess_Case1(string &pat,int p,int bpos[],int shift[])
{
	int i = p , j = p+1;
	
	bpos[i] = j;
	
	while(i > 0)
	{
		while(j <= p && pat[i-1] != pat[j-1])
		{
			if(shift[j] == 0)  shift[j] = j - i;
			
			j = bpos[j];
		}
		
		i--;
		
		j--;
		
		bpos[i] = j;
	}
}
void Preprocess_Case2(string &pat,int p,int bpos[],int shift[])
{
	int j = bpos[0];
	
	for(int i = 0 ; i <= p ; i++)
	{
		if(shift[i] == 0)  shift[i] = j;
		
		if(i == j)  j = bpos[j];
	}
}
void Search(string &s,int n,string &pat,int p)
{
    int bpos[p+1];
    
    int shift[p+1];  memset(shift,0,sizeof(shift));
    
    Preprocess_Case1(pat,p,bpos,shift);
    
    Preprocess_Case2(pat,p,bpos,shift);
    
    int i = 0;
    
    while(i <= n-p)
    {
    	int j = p-1;
    	
    	while(j >= 0 && pat[j] == s[i+j])
    	j--;
    	
    	if(j == -1)
    	cout<< i << " ";

		i += shift[j+1];
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
