#include<bits/stdc++.h>
using namespace std;

bool P[100];

void Sieve()
{
    memset(P , true , sizeof(P));
    
    for(int i = 2 ; i * i <= 100 ; i++)
    if(P[i])
    {
        for(int j = i * i ; j <= 100 ; j += i)
        P[j] = false;
    }
}

int Max_Ratio(int N)
{
	Sieve();
	
	int res = 1 , i = 2;
    
    while(res * i <= N)
    {
        if(P[i])
        res *= i;
        
        i++;
    }
    
    return res;
}

signed main()
{
	int N = 100;
	
	cout << Max_Ratio(N) << endl;
		
	return 0;
}
