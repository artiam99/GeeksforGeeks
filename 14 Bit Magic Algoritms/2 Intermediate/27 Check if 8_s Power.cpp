#include<bits/stdc++.h> 
using namespace std;
bool Check(int n)
{
	if((n & (n-1)))  return "No";
        
    int i = 0;
    
    while(n)
    {
        n>>=1;
        i++;
    }
    
    if(i == 1)  return "Yes";
    
    if(i < 4)  return "No";
    
    if(!((i-4) % 3))
    return "Yes";
    
    return "No";
}
int main() 
{
	int n = 64;
	
	if(Check(n))  cout << "YES" << endl;
	
	else  cout << "NO" << endl;
	
	return 0;
}

