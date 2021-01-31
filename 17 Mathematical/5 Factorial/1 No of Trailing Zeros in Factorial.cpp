#include<bits/stdc++.h>
using namespace std;

int Trailing_Zeros(int n)
{
	int cnt = 0 , i = 5;
	
	while(i <= n)
	{
		cnt += n / i;
		
		i *= 5;
	}
	
	return cnt;
}

signed main()
{
	int n = 384;
	
	cout << Trailing_Zeros(n) << endl;
		
	return 0;
}
