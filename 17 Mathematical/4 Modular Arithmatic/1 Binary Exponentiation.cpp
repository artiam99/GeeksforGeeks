#include<bits/stdc++.h>
using namespace std;

int Pow(int x , int n , int m)
{
	int res = 1;
	
    while (n > 0)
	{
        if (n & 1)
        res = (res % m * x % m) % m; 
    
	    x = (x % m * x % m) % m;
    
	    n >>= 1;
    }
    
	return res;
}

signed main()
{
	int x = 4 , n = 8 , m = 1000000007;  // Find (x ^ n ) % m
		
	cout << Pow(x , n , m) << endl;
		
	return 0;
}
