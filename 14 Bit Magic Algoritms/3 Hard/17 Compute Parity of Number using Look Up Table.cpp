#include <bits/stdc++.h>
using namespace std;
#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
#define LOOK_UP P6(0), P6(1), P6(1), P6(0)

unsigned int table[256] = { LOOK_UP };

bool Parity(int n)
{
	int max = 16;

    while(max >= 8)
	{ 
        n ^= (n >> max);
        
		max >>= 1;
    }

    return table[n & 0xff]; 
}
int main()
{
    int n = 3;
    
    cout << "Pairty of " << n << " is " << Parity(n) << endl;
 
    return 0;
}
