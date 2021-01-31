#include<bits/stdc++.h>
using namespace std;
bool check(string &s,int i,int j,int n)
{
	for(int k = 0 ; k < n ; k++)
	if(s[i+k] != s[j+k])
	return false;
	
	return true;
}
void Palindromic_Stream(string &s,int n)
{
	int mod = 1000000007 , d = 10;
	
	int first = 0 , second = 0;
	
	cout<< s[0] << " YES" << endl;
	
	int i = 0 , j = 1 , dec = 1;
	
	while(j < n)
	{
		first = (first % mod + (dec % mod * (s[i]-'a'+1) % mod ) % mod) % mod;
		
		second = ((second % mod * d % mod) % mod + (s[j]-'a'+1) % mod) % mod;
		
		if(first == second && check(s,0,i+1,i+1))  cout<< s[j] << " YES" << endl;
		
		else  cout<< s[j] << " NO" << endl;
		
		j++;
		
		if(j == n)  break;
		
		second = (((second - dec * (s[i+1]-'a'+1) + mod) % mod * d % mod ) % mod + (s[j]-'a'+1) % mod) % mod;
		
		if(first == second && check(s,0,i+2,i+1))  cout<< s[j] << " YES" << endl;
		
		else  cout<< s[j] << " NO" << endl;
		
		j++ , i++;
		
		dec = (dec % mod * d % mod) % mod;
	}
}
signed main()
{
	string s = "aabaacaabaa";// Wrong Modular Arithmatic tho
	int n = s.length();
	
	Palindromic_Stream(s,n);	
	
	return 0;
}
