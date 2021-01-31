#include<bits/stdc++.h> 
using namespace std;
bool Check(int n)
{
	if(!n)  return true;
	    
    int len = log2(n)+1;
    
    for(int i = 1 ; i <= len ; i++)
    {
        int x = n - i , cnt = 0;
        
        while(x > 0)
        {
            x &= (x-1);
            
            cnt++;
        }
        if(cnt == i)  return false;
    }
    return true;
}
int main() 
{ 
	int n = 4;  // If there exist any x for which  == >  x + Count_Set_Bit( x ) = n
	
	if(Check(n))  cout << "YES" << endl;
	
	else  cout << "NO" << endl;
	
	return 0; 
} 

