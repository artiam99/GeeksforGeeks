#include<bits/stdc++.h>
using namespace std;
bool check(int a,int b)
{
	return ((a ^ b) >> 31);
}
signed main()
{
	int a = 6 , b = -7;
	
	cout<< ((check(a,b)) ? "YES" : "NO") << endl;
	
	return 0;
}
