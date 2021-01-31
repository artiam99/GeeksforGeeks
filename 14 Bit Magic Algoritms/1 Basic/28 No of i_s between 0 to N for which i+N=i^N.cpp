#include <bits/stdc++.h> 
using namespace std;
int No_of_i(int n)
{
	int unsetbitcount = 0;
	
	while(n)
	{
		unsetbitcount += !(1 & n);
		
		n >>= 1;
	}
	
	return pow(2,unsetbitcount);
}
int main() 
{
	int n = 12;
	
	cout<< No_of_i(n) << endl;
	
	return 0; 
}
