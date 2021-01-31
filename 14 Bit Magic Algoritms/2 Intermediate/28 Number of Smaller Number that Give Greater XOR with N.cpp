#include<bits/stdc++.h> 
using namespace std;
int Greater_XOR_Number(int n)
{
	int ans = 0 , i = 0;
	
	while(n)
	{
		if(!(n & 1))  ans += (1 << i);
		
		n >>= 1;
		
		i++;
	}
	
	return ans;
}
int main() 
{
	int n = 20;
	
	cout << Greater_XOR_Number(n) << endl;
	
	return 0;
}

