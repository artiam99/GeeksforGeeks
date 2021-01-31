#include<bits/stdc++.h>
using namespace std;
void Search(string &s,int n,string &pat,int p)
{
	for(int i = 0 ; i < n ; i++)
	{
		int j;
		
		for(j = 0 ; j < p ; j++)
		if(s[i+j] != pat[j])
		break;
		
		if(j == p)
		{
			cout<< "Pattern Found at Index : " << i << endl;
			
			return;
		}
	}
	cout<< "Pattern Not Found" << endl;
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
