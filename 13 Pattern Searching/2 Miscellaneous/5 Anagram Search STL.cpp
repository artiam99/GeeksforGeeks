#include<bits/stdc++.h>
using namespace std;
void Search(string &s,int n,string &pat,int p)
{
	for(int i = 0 ; i < n ; i++)
	if(is_permutation(s.begin()+i,s.begin()+i+p,pat.begin()))
	cout<< i << " ";
	
	cout<< endl;
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
