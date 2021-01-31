#include<bits/stdc++.h>
using namespace std;
void Search(string &s,int n,string &pat,int p)
{
	int alpha1[26] , alpha2[26];  memset(alpha1,0,sizeof(alpha1));  memset(alpha2,0,sizeof(alpha2));
	
	for(int i = 0 ; i < p ; i++)
	alpha1[pat[i]-'A']++ , alpha2[s[i]-'A']++;
	
	for(int i = p ; i <= n ; i++)
	{
		int j;
		
		for(j = 0 ; j < 26 ; j++)
		if(alpha1[j] != alpha2[j])
		break;
		
		if(j == 26)
		cout<< i - p << " ";
		
		if(i == n)  break;
		
		alpha2[s[i]-'A']++;
		
		alpha2[s[i-p]-'A']--;
	}
}
signed main()
{
	string s = "AAABABAA";
	int n = s.length();
	
	string pat= "AABA";
	int p = pat.length();
	
	Search(s,n,pat,p);
	
	return 0;
}
