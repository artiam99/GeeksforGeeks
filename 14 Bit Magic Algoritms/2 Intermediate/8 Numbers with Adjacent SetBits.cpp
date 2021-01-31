#include<bits/stdc++.h> 
using namespace std;
int NumberofNumbers(int n)
{
	int x = 0 , y = 0;
        
    for(int i = 0 ; i < n-1 ; i++)
    {
        int c = y;
        
        y = x;
           
        x += c + (1 << i);
    }
    return x;
}
int main() 
{ 
	int n = 5;  // 00000 , 00001 , 00010 , 00011 , ... , 11111 ... 19 Numbers have adjacent Set Bits
	
	cout << NumberofNumbers(n) << endl;
	
	return 0; 
} 

