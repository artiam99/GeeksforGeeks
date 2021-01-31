#include<bits/stdc++.h>
using namespace std;
bool Rec(int i1,string &s,int n,int i2,string &pat,int p,map<char,string> &m)
{
	if(i1 == n && i2 == p)
	{
		for(auto i:m)
		cout<< i.first << " : " << i.second << endl;
		
		return true;
	}
	
	if(i1 == n)  return false;
	
	if(i2 == p)  return false;
	
	if(m.find(pat[i2]) == m.end())
	{
		for(int i = i1 ; i < n ; i++)
		{
			m[pat[i2]] = s.substr(i1,i-i1+1);
			
			if(Rec(i+1,s,n,i2+1,pat,p,m))
			return true;
			
			m.erase(pat[i2]);
		}
		return false;
	}
	else
	{
		int sz = m[pat[i2]].length();
		
		if(n - i1 + 1 < sz)  return false;
		
		if(m[pat[i2]] == s.substr(i1,sz))
		return Rec(i1+sz,s,n,i2+1,pat,p,m);
		
		return false;
	}
}
void Search(string &s,int n,string &pat,int p)
{
	map<char,string> m;
	
	Rec(0,s,n,0,pat,p,m);
}
signed main()
{
	string s = "GeeksforGeeks";
	int n = s.length();
	string pat = "aba";
	int p = pat.length();
	
	Search(s,n,pat,p);
	
	return 0;
}
