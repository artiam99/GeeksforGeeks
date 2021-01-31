#include<bits/stdc++.h> 
using namespace std;
int Abs(int n)
{
	int mask = (n >> 31);
	
	return (n + mask) ^ mask;
	
	/*  For Positive Numbers mask is 0 so after adding and Xoring , it doesn't change anything

	    For Negative Numbers mask is (2 ^ 32) - 1 so after adding n we get (2 ^ 32) - 1 + n = (2 ^ 32) + (n - 1)
	
	    So 2 ^ 32 will overflow and we will get n - 1
	
	    Xoring with mask will give us it's One's Complement  */
}
int main() 
{
	int n = -6;
	
	cout << Abs(n) << endl;
	
	int m = 5;
	
	cout << Abs(m) << endl;
	
	return 0;
}

