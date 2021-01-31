#include<bits/stdc++.h>
using namespace std;
int OFFRightMostSetBit(int a)
{
	return a - (a & -a);  // in Negative a Two's Complement's 1 is Added untill getting 0 .... in One's Complement First Zero Appers at the Right most Setbits's position in a
}
signed main()
{
	int a = 12;
	
	cout<< OFFRightMostSetBit(a) << endl;
	
	return 0;
}
