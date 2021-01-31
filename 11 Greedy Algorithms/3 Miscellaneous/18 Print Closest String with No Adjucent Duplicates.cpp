#include<bits/stdc++.h>
using namespace std;
string & Change(string &s,int n)
{
	for(int i = 1 ; i < n ; i++)
	{
		if(s[i] == s[i-1])
		{
			char l = s[i]-1 , r = s[i]+1;
			
			while(1)
			{
				if((i+1 == n || (s[i] != s[i+1])) && s[i] != s[i-1])
				break;
				
				if(l >= 'a')  s[i] = l;
				
				else  s[i] = r;
				
				l--;  r++;
			}
		}
	}
	return s;
}
signed main()
{
	string s = "geeksforgeeks";
	int n = s.length();
	
	cout<< Change(s,n) << endl;
	
    return 0;
}
