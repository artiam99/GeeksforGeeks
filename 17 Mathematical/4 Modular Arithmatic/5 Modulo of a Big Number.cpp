#include<bits/stdc++.h>
using namespace std;

int Mod(string &a , int m) // Simply generate the number with modulo m
{
	int res = 0;
	
	for(int i = 0 ; i < a.length() ; i++)
	res = ((res % m * 10 % m) % m + (a[i] - 48) % m) % m;
	
	return res;
}

signed main()
{
	string a = "123456789";
	int m = 10;
	
	cout << Mod(a , m) << endl;
		
	return 0;
}
