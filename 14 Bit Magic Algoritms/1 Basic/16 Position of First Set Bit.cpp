#include<bits/stdc++.h>
using namespace std;
int SetBitPos(int n)
{
	n = n & -n;  // Or N ^ ( N & (N-1)) ... First SetBit
	
	return log2(n) + 1;
	
	/*
		int cnt = 0;
		while(n)
		{
			n /= 2;
			cnt++;
		}
		return cnt;
	*/
}
signed main()
{
	int n = 18;
	
	cout<< SetBitPos(n) << endl;
	
	return 0;
}
