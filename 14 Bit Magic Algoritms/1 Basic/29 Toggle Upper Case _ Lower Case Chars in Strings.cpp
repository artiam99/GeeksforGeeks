#include <bits/stdc++.h> 
using namespace std;
string Toggle(string s)  // A = 65 = 1000001  ,  a = 97 = 1100001  .... To Togle Just Flip 6th Bit
{
	for(auto &i : s)
	i ^= 32;
	
	return s;
}
string Upper(string s)
{
	for(auto &i:s)
	i &= ~32;
	
	return s;
}
string Lower(string s)
{
	for(auto &i:s)
	i |= 32;
	
	return s;
}
int main() 
{
	string s = "Debarshi Maitra";
	
	cout<< Toggle(s) << endl;
	
	cout<< Upper(s) << endl;
	
	cout<< Lower(s) << endl;
	
	return 0; 
}
