#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

void Simple_Sieve(int sq , vector<int> &primes)
{
    bool P[sq+1];  memset(P,true,sizeof(P));
    
    for(int i = 2 ; i * i <= sq ; i++)
    if(P[i])
    {
        for(int j = i * i ; j <= sq ; j += i)
        P[j] = false;
    }
    
    for(int i = 2 ; i <= sq ; i++)
    if(P[i])
    primes.push_back(i);
    
}

void Segmented_Sieve(int l , int r , int sq , vector<int> &primes)
{   
    int low = l;
    
    int high = low + sq;
    
    while(low <= r)
    {
        if(high > r + 1)
		high = r + 1;
        
        bool P[high - low];  memset(P , true , sizeof(P));
        
        for(int i = 0 ; i < primes.size() && primes[i] * primes[i] <= r ; i++)
        {
            int curr = (low / primes[i]) * primes[i];
            
            if(curr < low)
            curr += primes[i];
            
            if(curr == primes[i])
            curr += primes[i];
            
            for(int j = curr ; j < high ; j += primes[i])
            P[j - low] = false;
        }
        
        for(int i = low ; i < high ; i++)
        if(P[i - low])
        cout << i << " ";
        
        low = high;
        
        high = low + sq;
    }
    
    cout << endl;
}

signed main()
{
	int mx = 1000000000;
	
	
	int sq = floor(sqrt(mx));
    
	vector<int> primes;
    
	Simple_Sieve(sq , primes);
	
	int l = 3456789 ,  r = 4568912;
	    
	Segmented_Sieve(l , r , sq , primes);
	
	return 0;
}

