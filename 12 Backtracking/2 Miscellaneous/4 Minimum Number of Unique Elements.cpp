#include<bits/stdc++.h>
using namespace std;
void Rec(string &a,string &b,int n,int i,unordered_set<char> &s,int &mn)
{
	if(i == n)
	{
		mn = min(mn , (int)s.size());
		
		return;
	}
	
	bool flag1 = (s.find(a[i]) == s.end());
	
	if(flag1)  s.insert(a[i]);
	
	Rec(a,b,n,i+1,s,mn);
	
	if(flag1)  s.erase(a[i]);
	
	bool flag2 = (s.find(b[i]) == s.end());
	
	if(flag2)  s.insert(b[i]);
	
	Rec(a,b,n,i+1,s,mn);
	
	if(flag2)  s.erase(b[i]);
}
int MinUnique(string &a,string &b,int n)
{
	int mn = INT_MAX;
	
	unordered_set<char> s;
	
	Rec(a,b,n,0,s,mn);
	
	return mn;
}
signed main()
{
	string a = "abbab";
	string b = "baaba";
	int n = a.length();
	
	cout<< MinUnique(a,b,n) << endl;
	
	return 0;
}
