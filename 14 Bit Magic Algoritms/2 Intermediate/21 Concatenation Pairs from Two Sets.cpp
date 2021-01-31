#include<bits/stdc++.h> 
using namespace std;
int Concatenation_Pairs(vector<string> &s1,int n,vector<string> &s2,int m)
{
	int con1[n];  memset(con1,0,sizeof(con1));
	
	int con2[m];  memset(con2,0,sizeof(con2));
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < s1[i].length() ; j++)
	con1[i] |= (1 << (s1[i][j] - 'a'));
	
	for(int i = 0 ; i < m ; i++)
	for(int j = 0 ; j < s2[i].length() ; j++)
	con2[i] |= (1 << (s2[i][j] - 'a'));
	
	int cnt = 0;
	
	for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < m ; j++)
	cnt += ((con1[i] | con2[j]) == ((1 << 26) - 1));
	
	return cnt;
}
int main() 
{ 
	vector<string> s1 = {"abcdefgh" , "geeksforgeeks" , "lmnopqrst" , "abc"};
	int n = s1.size();
	
	vector<string> s2 = {"ijklmnopqrstuvwxyz" , "abcdefghijklmnopqrstuvwxyz" , "defghijklmnopqrstuvwxyz"};
	int m = s2.size();
	
	cout << Concatenation_Pairs(s1,n,s2,m) << endl;
	
	return 0;
}

