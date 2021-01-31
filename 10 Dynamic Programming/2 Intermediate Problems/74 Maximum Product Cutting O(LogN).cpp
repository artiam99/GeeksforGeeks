#include<bits/stdc++.h>
using namespace std;
int MaxProdCutting(int n)
{
	if(n < 4) return n-1;// No Theory
                        // Just Observation
    
	long long x = ceil( (n - 4) / 3.0);
        
    return (n - 3 * x) * pow(3 , x);
}
signed main()
{
	int n = 10; // 3 * 3 * 4
	
	cout<< MaxProdCutting(n) <<endl;
    
	return 0;
}
