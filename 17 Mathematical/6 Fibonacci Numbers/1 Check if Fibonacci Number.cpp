#include<bits/stdc++.h>
using namespace std;

bool Check(int N)
{
	int k1 = 5 * N * N + 4 , k2 = 5 * N * N - 4;
	
    int sq1 = sqrt(k1) , sq2 = sqrt(k2);
    
	if(sq1 * sq1 == k1 || sq2 * sq2 == k2)
    return true;
    
	return false;
}

signed main()
{
	int N = 55;
	
	if(Check(N))  cout << "Fibonacci" << endl;
	
	else  cout << "Not Fibonacci" << endl;
	
	return 0;
}
