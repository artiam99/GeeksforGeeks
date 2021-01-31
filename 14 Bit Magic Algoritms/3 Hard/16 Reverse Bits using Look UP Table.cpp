#include <iostream>
#include <bitset>
using namespace std;
#define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64 
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16) 
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 ) 

unsigned int lookuptable[256] = { R6(0), R6(2), R6(1), R6(3) }; 

int Reverse_Bits(int n)
{
    int rev = lookuptable[ n & 0xff ] << 24 |
  
              lookuptable[ (n >> 8) & 0xff ] << 16 |
  
              lookuptable[ (n >> 16 ) & 0xff ] << 8 |
                   
              lookuptable[ (n >> 24 ) & 0xff ] ; 
    
    return rev; 
}
int main()
{
    int n = 1;
    
    cout << "Reversed Bits of " << n << " is " << Reverse_Bits(n) << endl;
 
    return 0;
}
