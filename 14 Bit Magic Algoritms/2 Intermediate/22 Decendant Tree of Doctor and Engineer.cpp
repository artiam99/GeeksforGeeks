#include<bits/stdc++.h> 
using namespace std;
bool Profession(int L,int P)
{
	L = min(L , (int)log2(P) + 2);
	    
    bool ans = 0;
    
    while(L >= 2)
    {
        if((1 << (L-2)) < P)
        {
            P -= (1 << (L - 2));
            
            ans = !ans;
        }
        
        L--;
    }
    return ans;
}
int main() 
{ 
/*            E
           /        
          E          D
        /          /  
       E     D     D    E
      /    /    /    / 
     E   D D   E  D  E  E  D
*/
	int Lev = 8 , Pos = 7;
	
	if(Profession(Lev , Pos))  cout << "Doctor" << endl;
    
    else  cout << "Engineer" << endl;
	
	return 0;
}

