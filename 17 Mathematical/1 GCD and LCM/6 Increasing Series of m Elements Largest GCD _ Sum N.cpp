#include <bits/stdc++.h>
using namespace std;

void Print_Series(int n , int m)
{
	int b = n / ((m * (m + 1)) / 2);  // Maximum Possible GCD to form an increasing series of size m and sum n
	
	if(b == 0)
	{
		cout << -1 << endl;
		
		return;
	}
	
	int g = 1;
	
	for(int i = 1 ; i * i <= n ; i++)
	{
		if(n % i != 0)  continue;
		
		if(i <= b && i > g)
		g = i;
		
		if(n / i <= b && n / i > g)
		g = n / i;
	}
	
	for(int i = 1 ; i <= m - 1 ; i++)
	cout << i * g << " ";
	
	cout << n - (g * ((m * (m - 1)) / 2)) << endl;
}

signed main()
{
    int n = 24 , m = 3;
    
    Print_Series(n , m);
    
    return 0;
}

