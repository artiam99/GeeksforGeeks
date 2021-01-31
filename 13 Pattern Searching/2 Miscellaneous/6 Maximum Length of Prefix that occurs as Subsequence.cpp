#include<bits/stdc++.h>
using namespace std;
int Search(string &s,int n,string &pat,int p)
{
	int j = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(pat[j] == s[i])
		j++;
		
		if(j == p)
		return p;
	}
	return j;
}
signed main()
{
	string s = "biggerdiagram";
	int n = s.length();
	
	string pat= "digger";
	int p = pat.length();
	
	cout<< Search(s,n,pat,p) << endl;
	
	return 0;
}
