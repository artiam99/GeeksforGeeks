#include<bits/stdc++.h>
using namespace std;
int FlippedBits(int a,int b)
{
	a = a ^ b;
	
	int cnt = 0;
	
	while(a)
	{
		a = a & (a-1);
		
		cnt++;
	}
	
	return cnt;
}
signed main()
{
	int a = 10 , b = 20;
	
	cout<< FlippedBits(a,b) << endl;
	
	return 0;
}
