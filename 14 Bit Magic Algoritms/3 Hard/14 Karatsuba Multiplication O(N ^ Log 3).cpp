#include<bits/stdc++.h> 
using namespace std;
string Add(string A,string B) 
{ 
    string res;
    int s = 0;

    int i = A.size() - 1, j = B.size() - 1;
    
    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0)? A[i] - '0' : 0); 
        s += ((j >= 0)? B[j] - '0' : 0); 

        res = char(s % 2 + '0') + res;

        s /= 2; 

        i--; j--; 
    } 
    return res; 
} 
string Multiply(string A,string B) // ab * cd = (a0 + b) * (c0 + d) = ac00 + bc0 + ad0 + bd
{	
    int a = A.length() , b = B.length();
    
    if(a == 1)  return ((A[0] == '0') ? "0" : B);
        
    if(b == 1)  return ((B[0] == '0') ? "0" : A);
    
    string ac = Multiply(A.substr(0 , a - (a >> 1)) , B.substr(0 , b - (b >> 1)));
    
    for(int i = 0 ; i < ((a >> 1) + (b >> 1)) ; i++)
    ac += '0';
    
    string bc = Multiply(A.substr(a - (a >> 1) , (a >> 1)) , B.substr(0 , b - (b >> 1)));
    
    for(int i = 0 ; i < (b >> 1) ; i++)
    bc += '0';
    
    string ad = Multiply(A.substr(0 , a - (a >> 1)) , B.substr(b - (b >> 1) , (b >> 1)));
    
    for(int i = 0 ; i < (a >> 1) ; i++)
    ad += '0';
    
    string bd = Multiply(A.substr(a - (a >> 1) , (a >> 1)) , B.substr(b - (b >> 1) , (b >> 1)));
    
    return Add(ac , Add(bc , Add(ad , bd)));
}
string Karatsuba(string A, string B)
{   
    return Multiply(A,B);
}
int main() 
{
	string A = "10111";
	string B = "10011";
	
	cout << Karatsuba(A,B) << endl;
	
	return 0;
}

