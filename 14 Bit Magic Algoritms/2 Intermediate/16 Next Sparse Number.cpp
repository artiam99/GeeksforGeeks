#include<bits/stdc++.h> 
using namespace std;
int MSB(int n)
{
    n |= (n >> 1);  n |= (n >> 2); n |= (n >> 4);  n |= (n >> 8);  n |= (n >> 16);  n++;  n >>= 1;
    
    return n;
}
int Next_Sparse(int n)//Find last Occurance of two Consecutive 1s , Find First Occurance to two Consecutive 0s after that bit , Make the first Zero One and Make all bits before it Zero
{
    if(!(n & (n >> 1))) return n;
    
    int i = MSB(n);
    
    while(i > 1)
    {
        if((i & n) && ((i >> 1) & n))
        break;
        
        i >>= 1;
    }
    
    if(i != 1)  i <<= 1;
    
    while(1)
    {
        if((i & n) == 0 && ((i << 1) & n) == 0)
        {
            n |= i;
            
            n &= ~(i - 1);
            
            return n;
        }
        i <<= 1;
    }
}
int main() 
{ 
	int n = 6334;
	
	cout << Next_Sparse(n) << endl;
	
	return 0; 
} 

