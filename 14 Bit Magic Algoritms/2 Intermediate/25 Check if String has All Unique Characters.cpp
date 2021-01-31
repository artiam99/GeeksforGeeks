#include<bits/stdc++.h> 
using namespace std;
bool Check(string &s,int n)
{
	int bit = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(bit & (1 << (s[i] - 'a')))
		return false;
		
		bit |= (1 << (s[i] - 'a'));
	}
	return true;
}
int main() 
{
	string s = "abcade";
	int n = s.length();
	
	if(Check(s,n))  cout << "YES" << endl;
	
	else  cout << "NO" << endl;
	
	return 0;
}

