#include<bits/stdc++.h>
using namespace std;
void Get_Z_Values(string &s,int n,int Z[])
{
	int L = 0 , R = 0 , k;
	
	for(int i = 1 ; i < n ; i++)
	{
		if(i > R)
		{
			L = R = i;
			
			while(R < n && s[R-L] == s[R])
			R++;
			
			Z[i] = R-L;
			
			R--;
		}
		else
		{
			k = i - L;
			
			if(Z[k] < R-i+1)
			Z[i] = Z[k];
			
			else
			{
				L = i;
				
				while(R < n && s[R-L] == s[R])
				R++;
				
				Z[i] = R-L;
				
				R--;
			}
		}
	}
}
void Search(string &s,int n,string &pat,int p)
{	
	string str = pat + '$' + s;
	int len = str.length();
	
	int Z[len];
	
	Get_Z_Values(str,len,Z);
	
	for(int i = p+1 ; i < len ; i++)
	if(Z[i] == p)
	cout<< i-p-1 << " ";
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
