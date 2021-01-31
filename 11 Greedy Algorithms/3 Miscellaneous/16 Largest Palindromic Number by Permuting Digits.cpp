#include<bits/stdc++.h>
using namespace std;
string PalPer(string &s,int n)
{
	int alpha[10];  memset(alpha,0,sizeof(alpha));
	
	for(int i = 0 ; i < n ; i++)
	alpha[s[i]-48]++;
	
	int odd = 0 , oddNo;
	
	for(int i = 0 ; i < 10 ; i++)
	if(alpha[i] % 2 == 1)
	odd++ , oddNo = i;
	
	if(odd > 1)
	return "Fuck Off";
	
	string s1 = s;
	
	if(n % 2 == 1)
	s1[n/2] = oddNo + 48;
	
	int l = 0 , r = n-1;
	
	while(l < r)
	{
		for(int i = 9 ; i >= 0 ; i--)
		if(alpha[i] >= 2)
		{
			s1[l] = s1[r] = i + 48;
			
			alpha[i] -= 2;
			
			l++;  r--;
			
			break;
		}
	}
	return s1;
}
signed main()
{
	string s = "3135517";
	int n = s.length();
	
	cout<< PalPer(s,n) << endl;
	
    return 0;
}
