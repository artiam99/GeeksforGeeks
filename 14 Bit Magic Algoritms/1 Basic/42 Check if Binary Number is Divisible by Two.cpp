#include <bits/stdc++.h> 
using namespace std;
bool Check(string &s,int n)  // Check if Abs Diff of Odd Setbits and Even Setbits is divisible by 3 or not
{
	int msb = 0 , even = 0 , odd = 0;
	    
    while(msb < n && s[msb] == '0') msb++;
    
    int i = n-1;
    
    while(i >= msb)
    {
        if(s[i] == '1')
        {
            if((n - i) & 1)  odd++;
            
            else  even++;
        }
        i--;
    }
    
    return (abs(odd - even) % 3 == 0);
}
int main() 
{
	string s = "0011";
	int n = s.length();
	
	if(Check(s,n))  cout << "YES" << endl;
	
	else  cout << "NO" << endl;
	
	return 0; 
}
