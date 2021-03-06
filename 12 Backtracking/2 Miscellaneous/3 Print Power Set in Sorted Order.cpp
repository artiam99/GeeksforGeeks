#include<bits/stdc++.h>
using namespace std;
void Rec(int a[],int i,string &s1)
{
	if(i == 26)
	{
		cout<< s1 << endl;
	
		return;
	}
	
	Rec(a,26,s1);
	
	for(int j = i ; j < 26 ; j++)
	if(a[j])
	{	
		a[j]--;
		
		s1.push_back(j+'a');
		
		Rec(a,j,s1);
	
		s1.pop_back();
		
		a[j]++;
	}
}
void PowerSet(string &s,int n)
{	
	int a[26];  memset(a,0,sizeof(a));
	
	for(int i = 0 ; i < n ; i++)
	a[s[i]-'a']++;
	
	string s1;
	
	Rec(a,0,s1);
}
signed main()
{
	string s = "aba";
	int n = s.length();
	
	PowerSet(s,n);
	
	return 0;
}
