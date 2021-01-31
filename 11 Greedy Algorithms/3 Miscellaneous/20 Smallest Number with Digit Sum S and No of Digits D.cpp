#include<bits/stdc++.h>
using namespace std;
string Smallest_Number(int S,int D)
{
	if(S > D * 9)  return "-1";
        
    string s;
    
    for(int i = 0 ; i < D ; i++)
    for(int j = ((i == 0) ? 1 : 0) ; j < 10 ; j++)
    if((D-i-1) * 9 >= S - j)
    {
        S -= j;
            
        s += (char)(j+48);
            
        break;
    }
    return s;
}
signed main()
{
	int S = 9 , D = 2;
	
	cout<< Smallest_Number(S,D) << endl;
	
    return 0;
}
