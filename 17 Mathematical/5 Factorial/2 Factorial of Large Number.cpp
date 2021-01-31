#include<bits/stdc++.h>
using namespace std;

string Factorial(int n)
{
	string s = "1";
	
	for(int i = 2 ; i <= n ; i++)
	{
		int carry = 0;
		
		for(int j = s.length() - 1 ; j >= 0 ; j--)
		{
			int res = (s[j] - 48) * i + carry;
			
			s[j] = (res % 10) + 48;
			
			carry = res / 10;
		}
		
		if(carry)
		{
			s = to_string(carry) + s;
		}
	}
	
	return s;
}

signed main()
{
	int n = 10;
	
	cout << Factorial(n) << endl;
		
	return 0;
}
