#include<bits/stdc++.h> 
using namespace std;
int ReverseBits(int n)
{
	int rev = 0; 

    while (n > 0) 
    {
    	rev <<= 1; 
    
    	if (n & 1 == 1) 
        rev ^= 1; 
        
        n >>= 1;      
    }
    return rev; 
}
int Nth_Palindromic_Number(int n)
{
	if(n == 1)  return 1;
	
	if(n == 2)  return 3;
	
	int len = 0 , curr = 0;
	
	while(1)
	{
		if(curr + (1 << ((len) / 2)) >= n)  break;
		
		curr += (1 << ((len) / 2));
		
		len++;
		
		if(curr + (1 << ((len) / 2)) >= n)  break;
		
		curr += (1 << ((len) / 2));
		
		len++;
	}
	
	len++;
	
	int m = n - curr - 1;
	
	int ans = (1 << (len - 1)) | 1;
	
	ans |= (m << (len >> 1));  // Left Half
	
	if(len & 1) m >>= 1;
	
	int sz = log2(m) + 1;
	
	m = ReverseBits(m);
	
	ans |= (m << ((len >> 1) - sz));  // Right Half
	
	return ans;
}
int main() 
{
	int n = 19;
	
	cout << Nth_Palindromic_Number(n) << endl;
	
	return 0;
}

