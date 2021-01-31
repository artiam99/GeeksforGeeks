#include<bits/stdc++.h>
using namespace std;
int CountSetBits(int n)
{
	int cnt = 0;
	
	while(n)
	{
		n = (n & (n-1));
		
		cnt++;
	}
	return cnt;
}
signed main()
{
	int n = 15;
	
	cout<< CountSetBits(n) << endl;
	
	return 0;
}
