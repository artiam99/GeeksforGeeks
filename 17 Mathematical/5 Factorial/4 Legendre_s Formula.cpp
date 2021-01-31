#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
	Legendre's Formula :  Prime Factorization of N!
	
	100!  = (2 ^ x) * (3 ^ y) * (5 ^ z) * ...
	
	x = 50 + 25 + 12 + 6 + 3 + 1
	
	y = 33 + 11 + 3 + 1
	
	z = 20 + 4
	
	why ...
	
	Let's see for 2
	
	2n ! = 2 ^ n * n! * (1 * 3 * 5 * 7 * ... * (2n - 1))
		 
		Do Recusive for n!
	
*/

void Sieve(bool P[] , int n)
{   
    for(int i = 2 ; i * i <= n ; i++)
    if(P[i])
    {
        for(int j = i * i ; j <= n ; j += i)
        P[j] = false;
    }
}

int No_of_Factors(int n)
{
	bool P[n+1];  memset(P , true , sizeof(P));
	
	Sieve(P , n);
	
	int ans = 1;
	    
    for(int i = 2 ; i <= n ; i++)
    if(P[i])
    {
        int x = n , cnt = 0;
        
        while(x)
        {
            x /= i;
            
            cnt += x;
        }
        
        ans *= (cnt + 1);
    }
    
    return ans;
}

signed main()
{
	int n = 99;
	
	cout << No_of_Factors(n) << endl;
		
	return 0;
}
