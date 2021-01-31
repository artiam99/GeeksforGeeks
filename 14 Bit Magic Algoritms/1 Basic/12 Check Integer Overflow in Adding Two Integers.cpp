#include<bits/stdc++.h>
using namespace std;
int Check(int a,int b)
{
	/*  Let's Assume it's a 8 Bit Representation (2's Complement)

		0    = 00000000
		1    = 00000001
		...
		127  = 01111111
		-128 = 10000000
		...
		-1   = 11111111
		
		Even if Maximum Positive Number is added Twice (For more than two numbers keep adding two in each step .... Adding all together won't work)
		
		127 + 127 (left shift by one) = 254 (11111110 ... 8 Bits) doesn't exceed the SignBit limit. So if any Two Positive Numbers in range are added and if Sum exceeds the Positive Limit , SignBit will be Changed to 1
		
		Same will happen for Negative Numbers
	*/
	return ((a > 0 && b > 0 && a+b < 0) || (a < 0 && b < 0 && a+b > 0));
}
signed main()
{
	int a = 2147483640 , b = 13;
	
	if(Check(a,b))  cout<< "Overflows" << endl;
	
	else  cout<< "Not Overflows" << endl;
	
	return 0;
}
