#include <bits/stdc++.h> 
using namespace std;
string TwosComplement(string &s,int n)
{
	for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == '0')  s[i] = '1';
        
        else  s[i] = '0';
    }
    
    int carry = 1 , i = n-1;
    
    while(i >= 0 && carry)
    {
        int cnt = 0;
        
        if(carry == 1)  cnt++;
        
        if(s[i] == '1')  cnt++;
        
        if(cnt == 0)  s[i--] = '0' , carry = 0;
        
        else if(cnt == 1)  s[i--] = '1' , carry = 0;
        
        else  s[i--] = '0' , carry = 1;
    }
    
    if(carry)  s.insert(s.begin() , '1');
    
    return s;
}
int main() 
{
	string s = "000110";
	int n = s.length();
	
	cout<< TwosComplement(s,n) << endl;
	
	return 0; 
}
