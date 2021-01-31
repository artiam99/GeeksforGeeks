#include <bits/stdc++.h>
using namespace std;
int Find(vector<int> &a,int n)
{
	int ones = 0 , tows = 0;
        
    for(int i = 0 ; i < n ; i++)
    {
        ones = (ones ^ a[i]) & ~tows;
    
	    tows = (tows ^ a[i]) & ~ones;
    }
    
    return ones;
}
int main() 
{
	vector<int> a = {12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7};
	int n = a.size();
	
	cout << Find(a,n) << endl;
	
	return 0; 
} 

