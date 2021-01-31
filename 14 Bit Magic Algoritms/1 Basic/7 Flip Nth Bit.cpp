#include<bits/stdc++.h>
using namespace std;
int FlipNthBit(int a,int n)
{
	return a ^ (1 << (n-1));
}
signed main()
{
	int a = 7 , n = 4;
	
	cout<< FlipNthBit(a,n) << endl;
	
	return 0;
}
