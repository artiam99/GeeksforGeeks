#include <bits/stdc++.h> 
using namespace std;
bool Check(int n)
{
	bool flag = false;
	
	while(n)
	{
		if(n & 1)
		{
			if(flag)  return true;
			
			flag = true;
		}
		else  flag = false;
		
		n >>= 1;
	}
	return false;
}
int main() 
{
	int n = 6;
	
	if(Check(n))  cout << "YES" << endl;
	
	else  cout << "NO" << endl;
	
	return 0; 
}
