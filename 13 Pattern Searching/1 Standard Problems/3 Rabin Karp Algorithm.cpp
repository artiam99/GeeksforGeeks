#include<bits/stdc++.h>
using namespace std;
void Search(string &s,int n,string &pat,int p)
{
	int mod = 1000000009 , d = 256;
	
	int Hash = 0 , curr = 0 , h = 1;
	
	for(int i = 0 ; i < p ; i++)
	{
		if(i < p-1)
		h = (h % mod * d % mod) % mod;
		
		Hash = ((Hash * d) % mod + pat[i] % mod) % mod;
		
		curr = ((curr * d) % mod + s[i] % mod) % mod;
	}
	
	for(int i = p ; i <= n ; i++)
	{
		if(curr == Hash && s.substr(i-p,p) == pat)
		{
			cout<< "Pattern Found at : " << i - p << endl;
				
			return;
		}
		
		if(i == n)
		break;
		
		curr = ((((curr - s[i-p] * h + mod ) % mod ) * d ) % mod + s[i] % mod ) % mod;
	}
	cout<< "Pattern Not Found" << endl;
}
signed main()
{
	string s = "ABAACAADAABAABA";
	int n = s.length();
	
	string pat = "AABA";
	int p = pat.length();
	
	Search(s,n,pat,p);
	
	return 0;
}
