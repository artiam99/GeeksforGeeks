#include <bits/stdc++.h> 
using namespace std;
string Octal(string &s,int n)
{
	string O;
	
	char ch = 0;
	
	for(int i = n-1 ; i >= 0 ; i--)
	{
		ch += pow(2,(n - i - 1) % 3) * (s[i] - 48);
		
		if((n-i) % 3 == 0)
		O.push_back(ch + 48) , ch = 0;
	}
	
	reverse(O.begin(),O.end());
	
	return O;
}
int main() 
{
	string s = "110001110";
	int n = s.length();
	
	cout<< Octal(s,n) << endl;
	
	return 0; 
}
