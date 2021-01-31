#include <bits/stdc++.h> 
using namespace std;
string Add(string &A,string &B)
{
	int i = A.length() - 1 , j = B.length() - 1 ;
	    
    bool carry = 0;
    
    string Sum;
    
    while(i >= 0 || j >= 0 || carry)
    {
         int cnt = 0;
         
         if(carry)  cnt++;
         
         if(i >= 0 && A[i] == '1')  cnt++;
         
         if(j >= 0 && B[j] == '1')  cnt++;
         
         if(cnt == 0)  Sum += '0' , carry = 0;
         
         else if(cnt == 1)  Sum += '1' , carry = 0;
         
         else if(cnt == 2)  Sum += '0' , carry = 1;
         
         else  Sum += '1' , carry = 1;
         
         if(i >= 0)  i--;
         
         if(j >= 0)  j--;
    }
    
    while(Sum.length() && Sum[Sum.length()-1] == '0')
    Sum.pop_back();
    
    reverse(Sum.begin(),Sum.end());
    
    return Sum;
}
int main() 
{
	string A = "11011";
	string B = "111";
	
	cout<< Add(A,B) << endl;
	
	return 0; 
}
