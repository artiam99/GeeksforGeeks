#include<bits/stdc++.h>
using namespace std;
void Palindromic_Stream(string &s,int n)
{
	cout<< s[0] << "  YES" << endl;
	
	int cnt = 1;
	
	for(int i = 1 ; i < n ; i++)
	{
		int l = i-1 , r = i;
		
		while(l >= 0 && s[l] == s[r])
		l-- , r++;
		
		if(l == -1)
		cout<< s[cnt] << "  YES" << endl;
		
		else
		cout<< s[cnt] << "  NO" << endl;
		
		cnt++;
		
		if(cnt == n)  break;
		
		l = i-1 , r = i+1;
		
		while(l >= 0 && s[l] == s[r])
		l-- , r++;
		
		if(l == -1)
		cout<< s[cnt] << "  YES" << endl;
		
		else
		cout<< s[cnt] << "  NO" << endl;
		
		cnt++;
		
		if(cnt == n)  break;
	}
}
signed main()
{
	string s = "aabaacaabaa";
	int n = s.length();
	
	Palindromic_Stream(s,n);	
	
	return 0;
}
