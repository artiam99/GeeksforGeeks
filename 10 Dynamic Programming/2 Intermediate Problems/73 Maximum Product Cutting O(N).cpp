#include<bits/stdc++.h>
using namespace std;
int MaxProdCutting(int n)
{
	if(n < 4)  return n-1;
	
	int res = 1;
	
	while(n > 4)
	{
		n -= 3;
		
		res *= 3;  // By Ovservation no Theory
	}
	return n * res;
}
signed main()
{
	int n = 10; // 3 * 3 * 4
	
	cout<< MaxProdCutting(n) <<endl;
    
	return 0;
}
