#include <iostream>
#include <bitset>
using namespace std;
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define COUNT_BITS B6(0), B6(1), B6(1), B6(2)

unsigned int lookup[256] = { COUNT_BITS };

int Set_Bit_Count(int n)
{
    int count = lookup[n & 0xff] +    			// consider first 8 bits
        		lookup[(n >> 8) & 0xff] +     // consider next 8 bits
        		lookup[(n >> 16) & 0xff] +    // consider next 8 bits
        		lookup[(n >> 24) & 0xff];    // consider last 8 bits
 
    return count;
}
int main()
{
    int n = 789;
    
    cout << "Number of Set Bits in " << n << " is " << Set_Bit_Count(n) << endl;
 
    return 0;
}
