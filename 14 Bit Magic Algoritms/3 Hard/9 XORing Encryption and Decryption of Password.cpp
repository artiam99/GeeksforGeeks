#include<bits/stdc++.h> 
using namespace std;
string Encrypt(string &s)
{
	int n = s.length();
	
	string E;
	
	for(int i = 0 ; i < 2 * n - 1 ; i++)
	E.push_back(0);
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < n ; j++)
	E[i + j] ^= s[j];
	
	return E;
}
string Decrypt(string &E)
{
	int n = E.length();
	
	string D;
	
	for(int i = 0 ; i < (n >> 1) + 1 ; i++)
	D.push_back(E[i]);
	
	for(int i = 0 ; i < (n >> 1) + 1 ; i++)
	for(int j = 0 ; j < i ; j++)
	D[i] ^= D[j];
	
	return D;
}
int main() 
{
	string s = "636f646572";
	
	string E = Encrypt(s);
	
	string D = Decrypt(E);
	
	cout << E << endl << endl << D << endl << endl;
	
	return 0;
}

