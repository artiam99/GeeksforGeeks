#include<bits/stdc++.h>
using namespace std;

int Factorial_Digit(int n)
{
	if(n <= 1)  return n;
	
	double ans = 0;
	
	for(int i = 2 ; i <= n ; i++)
	ans += log10(i);
	
	return ceil(ans);
}

signed main()
{
	int n = 10;
	
	cout << Factorial_Digit(n) << endl;
		
	return 0;
}
