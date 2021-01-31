#include<bits/stdc++.h>
using namespace std;
void Search(string &s,int n,string &pat,int p)
{
	int i = s.find(pat,0);
	
	while(i != string :: npos)
	{
		cout<< i << " ";
		
		i = s.find(pat,i+1);
	}
	
	cout<< endl;
}
signed main()
{
	string s = "aaabaaaab";
	int n = s.length();
	
	string pat= "aab";
	int p = pat.length();
	
	Search(s,n,pat,p);
	
	return 0;
}
